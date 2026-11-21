/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Each vertex initially parents itself; find follows parent pointers; union
links distinct roots.

Union 0,1 then 1,2 puts 0,1,2 in one set while 3 stays separate.

Linking roots merges exactly two disjoint trees without creating a parent cycle.

O(V) worst-case find/union in this deliberately unbalanced baseline; O(V) storage.

Changing a nonroot parent arbitrarily can detach only part of a component.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>
#include <numeric>

class Sets {
    std::vector<int> parent;

public:
    explicit Sets(int n)
        : parent(static_cast<std::size_t>(n)) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) const {
        while (parent[u] != u) {
            u = parent[u];
        }
        return u;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        parent[b] = a;
        return true;
    }
};

int main() {
    Sets s(4);
    assert(s.unite(0, 1));
    assert(s.unite(1, 2));
    assert(s.find(0) == s.find(2));
    assert(!s.unite(2, 0));
    assert(s.find(3) != s.find(0));
    std::cout << "checks passed\n";
    return 0;
}
