/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

indegree counts still-unprocessed incoming arcs; queue contains currently
eligible vertices.

0 and 1 are initially ready;2 enters only after both arcs into 2 are removed.

Every emitted vertex has no unprocessed prerequisite; if vertices remain without
a ready root, the residual graph has a cycle.

O(V+E) time, O(V) work.

A partial order on a cyclic graph must be reported as failure, not a complete
schedule.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <queue>
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

std::optional<std::vector<int>> topological(const Graph& g) {
    std::vector<int> indegree(g.size(), 0);
    for (const auto& row : g) {
        for (int v : row) {
            ++indegree[v];
        }
    }
    std::queue<int> q;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (indegree[u] == 0) {
            q.push(u);
        }
    }
    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            --indegree[v];
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (order.size() != g.size()) {
        return std::nullopt;
    }
    return order;
}

int main() {
    assert((topological(graph(3, {{0, 2}, {1, 2}}, true))
            == std::optional<std::vector<int>>{{0, 1, 2}}));
    assert(!topological(graph(2, {{0, 1}, {1, 0}}, true)));
    assert(topological({})->empty());
    std::cout << "checks passed\n";
    return 0;
}
