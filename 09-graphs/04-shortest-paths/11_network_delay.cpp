/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Run nonnegative Dijkstra, then take the maximum finite arrival only if all
destinations are reached.

The chain arrivals 0,2,5 require 5 total time; an isolated destination makes
broadcast completion impossible.

All recipients finish exactly when the slowest shortest arrival occurs.

O((V+E) log(E+1)) time, O(V+E) storage.

Ignoring unreachable vertices would return a falsely complete broadcast time.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
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

std::optional<long long> delay(const Weighted& g, int source) {
    auto d = dijkstra(g, source);
    long long best = 0;
    for (long long x : d) {
        if (x == INF) {
            return std::nullopt;
        }
        best = std::max(best, x);
    }
    return best;
}

int main() {
    assert(delay(weighted(3, {{0, 1, 2}, {1, 2, 3}}), 0) == 5);
    assert(!delay(weighted(2, {}), 0));
    std::cout << "checks passed\n";
    return 0;
}
