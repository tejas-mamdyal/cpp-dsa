/*
 Signed weighted graph; maxEdges 0..30; source/target valid; cycles are limited by
the explicit edge budget.

After step, d[v] is the best route using at most step edges. Read only the
previous snapshot when creating the next.

With one edge allowed 0->2 costs 5; two edges allow 0->1->2 cost 2.

A route of at most t+1 edges either uses at most t or appends one arc to a t-edge
route.

O(K*(V+E)) time, O(V) work.

In-place updates can propagate several edges in one pass and violate the budget.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

std::optional<long long>
bounded(int n, const std::vector<Edge>& edges, int source, int target, int maxEdges) {
    std::vector<long long> d(static_cast<std::size_t>(n), INF);
    d[source] = 0;
    for (int step = 0; step < maxEdges; ++step) {
        auto next = d;
        for (auto e : edges) {
            if (d[e.from] != INF) {
                next[e.to] = std::min(next[e.to], d[e.from] + e.weight);
            }
        }
        d = std::move(next);
    }
    if (d[target] == INF) {
        return std::nullopt;
    }
    return d[target];
}

int main() {
    assert(bounded(3, {{0, 1, 1}, {1, 2, 1}, {0, 2, 5}}, 0, 2, 1) == 5);
    assert(bounded(3, {{0, 1, 1}, {1, 2, 1}}, 0, 2, 2) == 2);
    assert(!bounded(3, {{0, 1, 1}, {1, 2, 1}}, 0, 2, 1));
    std::cout << "checks passed\n";
    return 0;
}
