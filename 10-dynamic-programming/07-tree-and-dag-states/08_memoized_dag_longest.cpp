/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

f(u) is maximum edge count of a directed path starting u. Memo stores
completed suffix values; active detects invalid cyclic dependencies.

Both diamond branches request f 3=0; it is computed once and reused.

In a DAG, the best path starts with one outgoing edge then an optimal suffix;
memoization preserves that recurrence.

O(V+E) time, O(V) cache/stack.

Caching a value before all its child dependencies finish can hide a directed cycle.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
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

int solve(const Graph& g, int u, std::vector<int>& memo, std::vector<bool>& active, bool& ok) {
    if (active[u]) {
        ok = false;
        return 0;
    }
    if (memo[u] != -1) {
        return memo[u];
    }
    active[u] = true;
    int best = 0;
    for (int v : g[u]) {
        best = std::max(best, 1 + solve(g, v, memo, active, ok));
        if (!ok) {
            break;
        }
    }
    active[u] = false;
    memo[u] = best;
    return best;
}

std::optional<int> longest(const Graph& g) {
    std::vector<int> memo(g.size(), -1);
    std::vector<bool> active(g.size(), false);
    bool ok = true;
    int best = 0;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        best = std::max(best, solve(g, u, memo, active, ok));
        if (!ok) {
            return std::nullopt;
        }
    }
    return best;
}

int main() {
    assert(longest(graph(4, {{0, 1}, {0, 2}, {1, 3}, {2, 3}}, true)) == 2);
    assert(!longest(graph(2, {{0, 1}, {1, 0}}, true)));
    assert(longest({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
