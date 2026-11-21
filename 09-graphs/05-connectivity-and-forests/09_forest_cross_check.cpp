/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Enumerate every subgraph of a small edge pool with negative and parallel
edges; compare weight and component count.

The empty mask gives weight 0 and four components in both algorithms.

Both independently proven cut-based algorithms solve the same forest objective;
agreement checks implementation and disconnected policies.

For a pool of m edges,2^m small test instances, each using the normal forest costs.

Weight equality alone would not check the disconnected-output convention.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <queue>
#include <functional>
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

std::pair<long long, int> prim(const Weighted& g) {
    std::vector<bool> seen(g.size(), false);
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        q;
    long long total = 0;
    int components = 0;
    for (int root = 0; root < static_cast<int>(g.size()); ++root) {
        if (seen[root]) {
            continue;
        }
        ++components;
        q.emplace(0, root);
        while (!q.empty()) {
            auto [weight, u] = q.top();
            q.pop();
            if (seen[u]) {
                continue;
            }
            seen[u] = true;
            total += weight;
            for (auto [v, w] : g[u]) {
                if (!seen[v]) {
                    q.emplace(w, v);
                }
            }
        }
    }
    return {total, components};
}

int main() {
    std::vector<Edge> pool{{0, 1, -2}, {0, 2, 3}, {1, 2, 1}, {2, 3, 0}, {0, 1, 4}};
    for (unsigned int mask = 0; mask < (1U << pool.size()); ++mask) {
        std::vector<Edge> edges;
        for (std::size_t i = 0; i < pool.size(); ++i) {
            if (mask & (1U << i)) {
                edges.push_back(pool[i]);
            }
        }
        auto a = kruskal(4, edges);
        auto b = prim(weighted(4, edges, false));
        assert(a.weight == b.first && a.components == b.second);
    }
    std::cout << "checks passed\n";
    return 0;
}
