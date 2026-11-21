/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

The intentionally invalid settled algorithm refuses to revisit a vertex
after choosing it as minimum.

Vertex 1 is settled at 2 before vertex 2 at 5 exposes edge 2->1=-10; the correct
answer is-5.

This counterexample invalidates the nonnegative finalization proof; Bellman-Ford
remains valid without a negative cycle.

Demonstration O(V^2+E); Bellman-Ford O(V*E).

The named wrong helper is a counterexample only, not a supported signed shortest-path
solver.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cstddef>

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

struct Bellman {
    std::vector<long long> distance;
    bool reachableNegativeCycle;
};

Bellman bellman(int n, const std::vector<Edge>& edges, int source) {
    std::vector<long long> d(static_cast<std::size_t>(n), INF);
    d[source] = 0;
    bool cycle = false;
    for (int pass = 0; pass < n; ++pass) {
        bool changed = false;
        for (auto e : edges) {
            if (d[e.from] != INF && d[e.from] + e.weight < d[e.to]) {
                d[e.to] = d[e.from] + e.weight;
                changed = true;
                if (pass == n - 1) {
                    cycle = true;
                }
            }
        }
        if (!changed) {
            break;
        }
    }
    return {d, cycle};
}

std::vector<long long> wrongSettled(const Weighted& g, int source) {
    std::vector<long long> d(g.size(), INF);
    std::vector<bool> done(g.size(), false);
    d[source] = 0;
    for (std::size_t step = 0; step < g.size(); ++step) {
        int u = -1;
        for (int v = 0; v < static_cast<int>(g.size()); ++v) {
            if (!done[v] && (u == -1 || d[v] < d[u])) {
                u = v;
            }
        }
        if (u == -1 || d[u] == INF) {
            break;
        }
        done[u] = true;
        for (auto [v, w] : g[u]) {
            if (!done[v]) {
                d[v] = std::min(d[v], d[u] + w);
            }
        }
    }
    return d;
}

int main() {
    std::vector<Edge> edges{{0, 1, 2}, {0, 2, 5}, {2, 1, -10}};
    assert(wrongSettled(weighted(3, edges), 0)[1] == 2);
    assert(bellman(3, edges, 0).distance[1] == -5);
    std::cout << "checks passed\n";
    return 0;
}
