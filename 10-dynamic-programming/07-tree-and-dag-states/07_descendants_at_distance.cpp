/*
 Valid rooted-at 0 tree, V<=30; k 0..30.

dp[u][d] counts descendants at exactly d edges below u under rooting 0;
only subtree descendants are eligible.

With edges 0-1,0-2,1-3, depth 1 descendant counts are 2,1,0,0.

Distance-d descendants uniquely lie at distance d-1 below one child; sum those
disjoint child sets.

O(V*K) time, O(V*K) active tables in this simple recursive version.

Ancestors and sibling branches are excluded; all-direction distance counts require
later rerooting.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
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

std::vector<int> solve(const Graph& g, int u, int parent, int k, std::vector<int>& answer) {
    std::vector<int> dp(static_cast<std::size_t>(k + 1), 0);
    dp[0] = 1;
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        auto child = solve(g, v, u, k, answer);
        for (int d = 1; d <= k; ++d) {
            dp[d] += child[d - 1];
        }
    }
    answer[u] = dp[k];
    return dp;
}

std::vector<int> counts(const Graph& g, int k) {
    std::vector<int> answer(g.size(), 0);
    if (!g.empty()) {
        solve(g, 0, -1, k, answer);
    }
    return answer;
}

int main() {
    assert((counts(graph(4, {{0, 1}, {0, 2}, {1, 3}}), 1) == std::vector<int>{2, 1, 0, 0}));
    assert((counts(graph(2, {{0, 1}}), 0) == std::vector<int>{1, 1}));
    std::cout << "checks passed\n";
    return 0;
}
