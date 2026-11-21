/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Sort undirected edges by weight; DSU rejects loops and cycle-forming
edges; retain component count and selected witness edges.

Choose 1-2 at-2 and 0-1 at 1; isolated 3 yields two-component forest of weight-1.

The lightest crossing edge is safe by a cut exchange; repeating inside each
connected component gives its MST.

O(E log(E+1)+V+E*alpha(V)) time, O(V+E) copied/witness storage.

Returning only total weight would hide that the graph is disconnected.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

int main() {
    auto f = kruskal(4, {{0, 1, 4}, {0, 1, 1}, {1, 2, -2}, {0, 2, 3}, {2, 2, -99}});
    assert(f.weight == -1 && f.components == 2 && f.edges.size() == 2);
    assert(kruskal(0, {}).weight == 0);
    std::cout << "checks passed\n";
    return 0;
}
