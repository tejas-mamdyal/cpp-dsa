/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

d is the best tentative distance; heap entries carry snapshots, which may
become stale after a better relaxation.

0 proposes 1 at 5 and 2 at 1;2 improves 1 to 2; the later heap entry(5,1) is
ignored.

A minimum unsettled distance cannot improve through nonnegative later edges;
relaxing all its arcs preserves the frontier invariant.

O((V+E) log(E+1)) time, O(V+E) possible heap/storage.

The proof fails with negative edges; all edge weights must be nonnegative.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
#include <functional>
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

std::vector<long long> dijkstra(const Weighted& g, int source) {
    std::vector<long long> d(g.size(), INF);
    std::priority_queue<std::pair<long long, int>,
                        std::vector<std::pair<long long, int>>,
                        std::greater<std::pair<long long, int>>>
        q;
    d[source] = 0;
    q.emplace(0, source);
    while (!q.empty()) {
        auto [snapshot, u] = q.top();
        q.pop();
        if (snapshot != d[u]) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            assert(w >= 0);
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
        }
    }
    return d;
}

int main() {
    auto d = dijkstra(weighted(4, {{0, 1, 5}, {0, 2, 1}, {2, 1, 1}}, true), 0);
    assert((d == std::vector<long long>{0, 2, 1, INF}));
    std::cout << "checks passed\n";
    return 0;
}
