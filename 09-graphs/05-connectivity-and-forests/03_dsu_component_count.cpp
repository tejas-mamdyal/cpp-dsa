/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Start with V singleton components; each successful union joins exactly
two.

Duplicate 0-1 and loop 3-3 do not reduce the count beyond the two real merges.

A redundant edge stays within one partition block; only distinct-block union
reduces block count by 1.

O(V+E*alpha(V)) time, O(V) storage.

Decrementing for every input edge undercounts when edges repeat or cycles exist.
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

int countComponents(int n, const std::vector<std::pair<int, int>>& edges) {
    DSU dsu(n);
    int count = n;
    for (auto [u, v] : edges) {
        if (dsu.unite(u, v)) {
            --count;
        }
    }
    return count;
}

int main() {
    assert(countComponents(5, {{0, 1}, {1, 0}, {2, 3}, {3, 3}}) == 3);
    assert(countComponents(0, {}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
