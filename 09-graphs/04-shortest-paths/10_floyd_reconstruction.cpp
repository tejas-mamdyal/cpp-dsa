/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

When a split through k improves i->j, the new first hop is next[i][k].
Return absence for unreachable or unbounded pairs.

0->2 improves via 1, so its first hop is 1, and 1->2 supplies the final step.

Each next hop lies on a strictly improved route; excluding cycle-affected pairs
leaves a finite simple shortest witness.

O(V^3) time, O(V^2) storage plus path.

Do not follow next hops through a reachable negative cycle; that can loop forever.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
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

std::optional<std::vector<int>>
floydRoute(int n, const std::vector<Edge>& edges, int source, int target) {
    std::vector<std::vector<long long>> d(static_cast<std::size_t>(n),
                                          std::vector<long long>(static_cast<std::size_t>(n), INF));
    std::vector<std::vector<int>> next(static_cast<std::size_t>(n),
                                       std::vector<int>(static_cast<std::size_t>(n), -1));
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
        next[i][i] = i;
    }
    for (auto e : edges) {
        if (e.weight < d[e.from][e.to]) {
            d[e.from][e.to] = e.weight;
            next[e.from][e.to] = e.to;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = std::max(
                        -INF,
                        d[i][k]
                            + d[k][j]); // Both summands are at least -INF,so their sum still fits.
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    if (next[source][target] == -1) {
        return std::nullopt;
    }
    for (int k = 0; k < n; ++k) {
        if (d[source][k] != INF && d[k][k] < 0 && d[k][target] != INF) {
            return std::nullopt;
        }
    }
    std::vector<int> path{source};
    while (source != target) {
        source = next[source][target];
        path.push_back(source);
        assert(path.size() <= static_cast<std::size_t>(n + 1));
    }
    return path;
}

int main() {
    assert((floydRoute(3, {{0, 1, 2}, {1, 2, 1}}, 0, 2)
            == std::optional<std::vector<int>>{{0, 1, 2}}));
    assert(!floydRoute(2, {{0, 1, -1}, {1, 0, 0}}, 0, 1));
    assert(!floydRoute(2, {}, 0, 1));
    std::cout << "checks passed\n";
    return 0;
}
