/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

size is meaningful at roots; recursive find replaces each visited parent
by the representative.

Two size 2 groups join to size 4; future finds jump directly toward their shared
root.

Compression preserves component identity; size linking maintains a forest and
correct root sizes.

Amortized O(alpha(V)) per operation, O(V) storage; alpha is inverse Ackermann and grows
extremely slowly.

Component size belongs to the root, not every compressed vertex entry.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstddef>
#include <numeric>

class DSU {
    std::vector<int> parent;
    std::vector<int> size;

public:
    explicit DSU(int n)
        : parent(static_cast<std::size_t>(n)),
          size(static_cast<std::size_t>(n), 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (size[a] < size[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int count(int u) {
        return size[find(u)];
    }
};

int main() {
    DSU s(6);
    s.unite(0, 1);
    s.unite(2, 3);
    s.unite(1, 3);
    assert(s.count(0) == 4);
    assert(s.find(0) == s.find(2));
    assert(!s.unite(0, 3));
    assert(s.count(5) == 1);
    std::cout << "checks passed\n";
    return 0;
}
