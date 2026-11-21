/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Process edges in input order; failed union identifies already-connected
endpoints.

After 0-1 and 1-2, the edge 2-0 joins one existing component to itself.

A prior endpoint path plus the new edge forms a cycle exactly when the endpoints
were connected.

O(V+E*alpha(V)) time, O(V) work.

DSU cycle detection here is undirected; it does not detect directed cycles correctly.
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

std::optional<std::pair<int, int>> firstRedundant(int n,
                                                  const std::vector<std::pair<int, int>>& edges) {
    DSU dsu(n);
    for (auto e : edges) {
        if (!dsu.unite(e.first, e.second)) {
            return e;
        }
    }
    return std::nullopt;
}

int main() {
    assert((firstRedundant(3, {{0, 1}, {1, 2}, {2, 0}})
            == std::optional<std::pair<int, int>>{{2, 0}}));
    assert(!firstRedundant(3, {{0, 1}, {1, 2}}));
    assert(firstRedundant(1, {{0, 0}}));
    std::cout << "checks passed\n";
    return 0;
}
