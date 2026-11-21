/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Unseen/active/finished states provide cycle detection; append after
descendants finish.

Chain 0->1->2 finishes 2,1,0 and reverses to 0,1,2.

For each DAG edge, its destination finishes before source or was already
finished; reversal places source first.

O(V+E) time, O(V) stack/state/order.

A plain visited-only DFS may output a misleading ordering for a cycle.
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

bool finish(const Graph& g, int u, std::vector<int>& state, std::vector<int>& order) {
    state[u] = 1;
    for (int v : g[u]) {
        if (state[v] == 1) {
            return false;
        }
        if (state[v] == 0 && !finish(g, v, state, order)) {
            return false;
        }
    }
    state[u] = 2;
    order.push_back(u);
    return true;
}

std::optional<std::vector<int>> dfsOrder(const Graph& g) {
    std::vector<int> state(g.size(), 0);
    std::vector<int> order;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (state[u] == 0 && !finish(g, u, state, order)) {
            return std::nullopt;
        }
    }
    std::reverse(order.begin(), order.end());
    return order;
}

int main() {
    assert(
        (dfsOrder(graph(3, {{0, 1}, {1, 2}}, true)) == std::optional<std::vector<int>>{{0, 1, 2}}));
    assert(!dfsOrder(graph(1, {{0, 0}}, true)));
    std::cout << "checks passed\n";
    return 0;
}
