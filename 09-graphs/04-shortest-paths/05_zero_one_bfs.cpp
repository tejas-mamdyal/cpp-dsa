/*
 Directed weighted graph with only 0/1 edge weights; source valid. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

A deque replaces the general heap because frontier distances differ by at
most one unit.

0 reaches 2 free, then 1 free, improving the initially cost 1 route to 1.

Front insertion preserves minimum-distance processing for cost 0; back insertion
preserves the next cost layer for cost 1.

O(V+E) time, O(V+E) bounded queued snapshots.

Weights outside 0/1 require another algorithm.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <limits>
#include <deque>
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

std::vector<long long> zeroOne(const Weighted& g, int source) {
    std::vector<long long> d(g.size(), INF);
    std::deque<std::pair<int, long long>> q;
    d[source] = 0;
    q.emplace_front(source, 0);
    while (!q.empty()) {
        auto [u, snapshot] = q.front();
        q.pop_front();
        if (snapshot != d[u]) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            assert(w == 0 || w == 1);
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (w == 0) {
                    q.emplace_front(v, d[v]);
                } else {
                    q.emplace_back(v, d[v]);
                }
            }
        }
    }
    return d;
}

int main() {
    assert((zeroOne(weighted(4, {{0, 1, 1}, {0, 2, 0}, {2, 1, 0}}), 0)
            == std::vector<long long>{0, 0, 0, INF}));
    std::cout << "checks passed\n";
    return 0;
}
