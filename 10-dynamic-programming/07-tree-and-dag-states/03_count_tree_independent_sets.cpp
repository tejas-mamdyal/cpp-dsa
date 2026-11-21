/*
 Valid tree, V<=30; count positional vertex subsets, including empty. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[u][0/1] counts valid subsets conditioned on u being excluded/included;
each empty child collection has multiplicative identity 1.

For one edge, the allowed subsets are empty, left, right, total 3.

Child subtree assignments are independent products after fixing u; the two root
states are disjoint alternatives.

O(V) time, O(height) stack; counts bounded by 2^30.

Summing children instead of multiplying loses combinations across independent
branches.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <array>
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

std::array<long long, 2> ways(const Graph& g, int u, int parent) {
    std::array<long long, 2> dp{1, 1};
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        auto child = ways(g, v, u);
        dp[0] *= child[0] + child[1];
        dp[1] *= child[0];
    }
    return dp;
}

long long count(const Graph& g) {
    if (g.empty()) {
        return 1;
    }
    auto dp = ways(g, 0, -1);
    return dp[0] + dp[1];
}

int main() {
    assert(count(graph(2, {{0, 1}})) == 3);
    assert(count(graph(3, {{0, 1}, {0, 2}})) == 5);
    assert(count({}) == 1);
    std::cout << "checks passed\n";
    return 0;
}
