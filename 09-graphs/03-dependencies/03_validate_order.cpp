/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

position maps each vertex to one rank after verifying a complete
permutation.

Both 1,0,2 and 0,1,2 satisfy the two prerequisites of 2.

All arcs point forward exactly when the claimed permutation is topological.

O(V+E) time, O(V) positions.

Comparing to one stored expected order rejects other equally valid orders.
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

bool validOrder(const Graph& g, const std::vector<int>& order) {
    if (order.size() != g.size()) {
        return false;
    }
    std::vector<int> position(g.size(), -1);
    for (int i = 0; i < static_cast<int>(order.size()); ++i) {
        int u = order[i];
        if (u < 0 || u >= static_cast<int>(g.size()) || position[u] != -1) {
            return false;
        }
        position[u] = i;
    }
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        for (int v : g[u]) {
            if (position[u] >= position[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    auto g = graph(3, {{0, 2}, {1, 2}}, true);
    assert(validOrder(g, {1, 0, 2}));
    assert(!validOrder(g, {2, 0, 1}));
    assert(!validOrder(g, {0, 0, 2}));
    assert(validOrder({}, {}));
    std::cout << "checks passed\n";
    return 0;
}
