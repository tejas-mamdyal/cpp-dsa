/*
 Valid tree, V<=30; cover every edge with selected endpoints. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

dp[u][0/1] is minimum cover size in subtree u under exclusion/inclusion;
excluded u forces every child included.

A star is covered by choosing its center once instead of all three leaves.

The parent-child edge constraint determines each compatible child state; minimum
sums combine independent subtrees.

O(V) time, O(height) recursion.

Independent-set and vertex-cover recurrences reverse different constraints; derive
them instead of copying signs.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

std::array<int, 2> cover(const Graph& g, int u, int parent) {
    std::array<int, 2> dp{0, 1};
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        auto child = cover(g, v, u);
        dp[0] += child[1];
        dp[1] += std::min(child[0], child[1]);
    }
    return dp;
}

int minimum(const Graph& g) {
    if (g.empty()) {
        return 0;
    }
    auto dp = cover(g, 0, -1);
    return std::min(dp[0], dp[1]);
}

int main() {
    assert(minimum(graph(4, {{0, 1}, {0, 2}, {0, 3}})) == 1);
    assert(minimum(graph(1, {})) == 0);
    assert(minimum({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
