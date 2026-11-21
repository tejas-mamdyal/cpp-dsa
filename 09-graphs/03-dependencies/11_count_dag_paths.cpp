/*
 Directed acyclic graph, V<=20, E<=40; source/target valid; cycles return absence.

ways[v] counts source-to-v routes; seed the empty source route with 1.
Parallel arcs count as distinct edge routes.

The diamond sends one route through 1 and one through 2 into 3, total 2.

Every nonempty route into v has a unique final incoming arc; sum predecessor
counts over those arcs.

O(V+E) time, O(V) states; limit V<=20, E<=40 so counts fit long long.

This local recurrence is explicitly introduced here; full DP design and counting
overflow policies follow in Phase 7.
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

std::optional<long long> pathCount(const Graph& g, int source, int target) {
    auto order = topological(g);
    if (!order) {
        return std::nullopt;
    }
    std::vector<long long> ways(g.size(), 0);
    ways[source] = 1;
    for (int u : *order) {
        for (int v : g[u]) {
            ways[v] += ways[u];
        }
    }
    return ways[target];
}

int main() {
    assert(pathCount(graph(4, {{0, 1}, {0, 2}, {1, 3}, {2, 3}}, true), 0, 3) == 2);
    assert(pathCount(graph(2, {}, true), 0, 1) == 0);
    std::cout << "checks passed\n";
    return 0;
}
