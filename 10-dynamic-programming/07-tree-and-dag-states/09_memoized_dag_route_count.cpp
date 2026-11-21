/*
 Valid directed acyclic graph, V<=20, E<=40; source/target valid; parallel arcs
distinguish routes.

f(u) counts routes from u to the fixed target; reaching target contributes
one empty continuation.

At diamond source 0, one suffix route via 1 and one via 2 add to 2.

Each nonempty route has a unique first outgoing arc; DAG acyclicity ensures
recursive termination.

O(V+E) time, O(V) states/stack.

Validate acyclicity before using this helper on external input; its contract is a
DAG.
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

long long solve(const Graph& g, int u, int target, std::vector<long long>& memo) {
    if (u == target) {
        return 1;
    }
    if (memo[u] != -1) {
        return memo[u];
    }
    long long ways = 0;
    for (int v : g[u]) {
        ways += solve(g, v, target, memo);
    }
    memo[u] = ways;
    return ways;
}

long long count(const Graph& g, int source, int target) {
    std::vector<long long> memo(g.size(), -1);
    return solve(g, source, target, memo);
}

int main() {
    assert(count(graph(4, {{0, 1}, {0, 2}, {1, 3}, {2, 3}}, true), 0, 3) == 2);
    assert(count(graph(2, {}, true), 0, 1) == 0);
    assert(count(graph(1, {}, true), 0, 0) == 1);
    std::cout << "checks passed\n";
    return 0;
}
