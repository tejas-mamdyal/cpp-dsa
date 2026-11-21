/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

For this convention, a tree has at least one vertex and V-1 edges; reject
any failed union.

One vertex with no edges is a tree; two parallel 0-1 edges at n 3 form a cycle and
leave 2 isolated.

An acyclic undirected graph with V vertices and V-1 successful joins has exactly
one component.

O(V+E*alpha(V)) time, O(V) storage.

State the empty-tree convention rather than relying on a size_t n-1 underflow.
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

bool isTree(int n, const std::vector<std::pair<int, int>>& edges) {
    if (n < 1 || edges.size() != static_cast<std::size_t>(n - 1)) {
        return false;
    }
    DSU dsu(n);
    for (auto [u, v] : edges) {
        if (!dsu.unite(u, v)) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(isTree(3, {{0, 1}, {1, 2}}));
    assert(!isTree(3, {{0, 1}, {0, 1}}));
    assert(isTree(1, {}));
    assert(!isTree(0, {}));
    std::cout << "checks passed\n";
    return 0;
}
