/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Use the forest solver, then enforce the requested connectivity contract.
Empty input is assigned cost 0 by convention.

Two connected vertices plus an isolated third produce a valid forest but no
spanning tree.

A spanning tree exists exactly when the nonempty graph has one connected
component.

Kruskal O(E log(E+1)+V) plus DSU factors.

Minimum spanning forest and minimum spanning tree are distinct outputs.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>
#include <limits>
#include <cstddef>
#include <numeric>

struct Edge {
    int from;
    int to;
    int weight;
};

using Weighted = std::vector<std::vector<std::pair<int, int>>>;
constexpr long long INF = std::numeric_limits<long long>::max() / 4;

Weighted weighted(int n, const std::vector<Edge>& edges, bool directed = true) {
    Weighted g(static_cast<std::size_t>(n));
    for (auto e : edges) {
        g[e.from].emplace_back(e.to, e.weight);
        if (!directed) {
            g[e.to].emplace_back(e.from, e.weight);
        }
    }
    return g;
}

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

struct Forest {
    long long weight;
    int components;
    std::vector<Edge> edges;
};

Forest kruskal(int n, std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    DSU dsu(n);
    Forest out{0, n, {}};
    for (auto e : edges) {
        if (dsu.unite(e.from, e.to)) {
            out.weight += e.weight;
            --out.components;
            out.edges.push_back(e);
        }
    }
    return out;
}

std::optional<long long> mst(int n, const std::vector<Edge>& edges) {
    auto f = kruskal(n, edges);
    if (n > 0 && f.components != 1) {
        return std::nullopt;
    }
    return f.weight;
}

int main() {
    assert(mst(3, {{0, 1, 2}, {1, 2, 1}, {0, 2, 7}}) == 3);
    assert(!mst(3, {{0, 1, 2}}));
    assert(mst(0, {}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
