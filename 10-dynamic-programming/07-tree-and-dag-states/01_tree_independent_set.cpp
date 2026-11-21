/*
 Valid undirected connected tree, V<=30; empty graph returns 0. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

dp[u][0/1] is maximum selected vertex count in subtree u with u
excluded/included; included u forbids included children.

A four-vertex star chooses three leaves instead of its center.

After fixing u inclusion, child subtrees are independent and each contributes its
best compatible state.

O(V) time, O(height) recursion; input tree storage O(V).

Taking every child maximum even when u is included would violate edge independence.
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

std::array<int, 2> independent(const Graph& g, int u, int parent) {
    std::array<int, 2> dp{0, 1};
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        auto child = independent(g, v, u);
        dp[0] += std::max(child[0], child[1]);
        dp[1] += child[0];
    }
    return dp;
}

int best(const Graph& g) {
    if (g.empty()) {
        return 0;
    }
    auto dp = independent(g, 0, -1);
    return std::max(dp[0], dp[1]);
}

int main() {
    assert(best(graph(4, {{0, 1}, {0, 2}, {0, 3}})) == 3);
    assert(best(graph(4, {{0, 1}, {1, 2}, {2, 3}})) == 2);
    assert(best({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
