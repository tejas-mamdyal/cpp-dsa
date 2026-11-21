/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Repeatedly relax all edges; after V-1 passes every finite simple route can
be represented. An additional improvement witnesses a reachable negative cycle.

0->1=2,1->2=-5 gives-3; an unreachable negative cycle is skipped because its start
distance is INF.

Without reachable negative cycles, a shortest route can be made simple and uses
at most V-1 edges; continued improvement contradicts that bound.

O(V*E) time, O(V) distances.

Distances on or downstream of a reachable negative cycle are not finite answers even
if stored as numbers.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

int main() {
    auto a = bellman(4, {{0, 1, 2}, {1, 2, -5}}, 0);
    assert(!a.reachableNegativeCycle && a.distance[2] == -3 && a.distance[3] == INF);
    assert(bellman(2, {{0, 1, -1}, {1, 0, -1}}, 0).reachableNegativeCycle);
    assert(!bellman(3, {{1, 2, -1}, {2, 1, -1}}, 0).reachableNegativeCycle);
    std::cout << "checks passed\n";
    return 0;
}
