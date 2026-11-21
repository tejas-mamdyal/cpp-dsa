/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

A failed union yields an edge that can be removed without splitting its
current connected component; one spare can join two components.

A triangle plus one isolated vertex has one spare edge and needs one connection.

Connecting C components needs C-1 edges; available redundant edges can be
relocated without losing internal connectivity.

O(V+E*alpha(V)) time, O(V) auxiliary.

This assumes cable relocation between arbitrary vertices is permitted.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
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

std::optional<int> rewires(int n, const std::vector<std::pair<int, int>>& edges) {
    if (n <= 1) {
        return 0;
    }
    DSU dsu(n);
    int components = n;
    int spare = 0;
    for (auto [u, v] : edges) {
        if (dsu.unite(u, v)) {
            --components;
        } else {
            ++spare;
        }
    }
    if (spare < components - 1) {
        return std::nullopt;
    }
    return components - 1;
}

int main() {
    assert(rewires(4, {{0, 1}, {0, 2}, {1, 2}}) == 1);
    assert(!rewires(4, {{0, 1}, {2, 3}}));
    assert(rewires(0, {}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
