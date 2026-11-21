/*
 Tree V<=20; root 0 must be included; k 1..V; one signed value per vertex. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[u][s] is maximum reward of exactly s connected selected vertices inside
subtree u including u. Skipping a child uses its 0 selection implicitly.

Root 5 with leaves-100 and 4 selects root plus 4 for budget 2, reward 9.

A connected rooted selection intersects each used child subtree in a connected
selection containing that child; budget convolution tries every size split.

O(V*K^2) time, O(V*K) worst-case active tables.

Selecting arbitrary descendant items without their connecting ancestors violates
connectivity.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>
#include <limits>
#include <cstddef>

using Graph = std::vector<std::vector<int>>;

Graph graph(int n, const std::vector<std::pair<int, int>>& edges, bool directed = false) {
    assert(n >= 0);
    Graph g(static_cast<std::size_t>(n));
    for (auto [u, v] : edges) {
        assert(u >= 0 && v >= 0 && u < n && v < n);
        g[u].push_back(v);
        if (!directed) {
            g[v].push_back(u);
        }
    }
    return g;
}

constexpr long long NEG = std::numeric_limits<long long>::lowest() / 4;

std::vector<long long>
solve(const Graph& g, const std::vector<int>& value, int u, int parent, int k) {
    std::vector<long long> dp(static_cast<std::size_t>(k + 1), NEG);
    dp[1] = value[u];
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        auto child = solve(g, value, v, u, k);
        auto next = dp;
        for (int own = 1; own <= k; ++own) {
            for (int take = 1; own + take <= k; ++take) {
                if (dp[own] != NEG && child[take] != NEG) {
                    next[own + take] = std::max(next[own + take], dp[own] + child[take]);
                }
            }
        }
        dp = std::move(next);
    }
    return dp;
}

std::optional<long long> connected(const Graph& g, const std::vector<int>& value, int k) {
    if (g.empty() || k < 1 || k > static_cast<int>(g.size())) {
        return std::nullopt;
    }
    auto dp = solve(g, value, 0, -1, k);
    if (dp[k] == NEG) {
        return std::nullopt;
    }
    return dp[k];
}

int main() {
    auto g = graph(3, {{0, 1}, {0, 2}});
    assert(connected(g, {5, -100, 4}, 2) == 9);
    assert(connected(g, {5, -100, 4}, 3) == -91);
    assert(!connected(g, {5, -100, 4}, 0));
    std::cout << "checks passed\n";
    return 0;
}
