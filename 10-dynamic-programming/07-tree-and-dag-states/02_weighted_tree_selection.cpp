/*
 Valid undirected tree, V<=30, one signed reward per vertex; empty selection allowed.

dp[u][chosen] is maximum total reward in subtree u under that root
condition; excluding all vertices is allowed.

Root reward 10 beats its two leaves 4+5; all-negative input selects nothing for 0.

The same compatibility decomposition applies to additive rewards rather than unit
counts.

O(V) time, O(height) stack.

If nonempty selection is required, the empty 0 state needs an extra feasibility
condition.
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

std::array<long long, 2> solve(const Graph& g, const std::vector<int>& values, int u, int parent) {
    std::array<long long, 2> dp{0, values[u]};
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        auto child = solve(g, values, v, u);
        dp[0] += std::max(child[0], child[1]);
        dp[1] += child[0];
    }
    return dp;
}

long long best(const Graph& g, const std::vector<int>& values) {
    if (g.empty()) {
        return 0;
    }
    auto dp = solve(g, values, 0, -1);
    return std::max(dp[0], dp[1]);
}

int main() {
    assert(best(graph(3, {{0, 1}, {0, 2}}), {10, 4, 5}) == 10);
    assert(best(graph(2, {{0, 1}}), {-3, -2}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
