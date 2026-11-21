/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Input pairs(course, prerequisite) become arcs prerequisite->course before
Kahn.

Course 2 requires 1 which requires 0, so order 0,1,2 works.

A feasible schedule is exactly a topological order of prerequisite arcs.

O(V+E) time/storage.

Document pair orientation rather than guessing it from the algorithm.
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

bool canFinish(int n, const std::vector<std::pair<int, int>>& coursePrerequisite) {
    std::vector<std::pair<int, int>> arcs;
    for (auto [course, prerequisite] : coursePrerequisite) {
        arcs.emplace_back(prerequisite, course);
    }
    return topological(graph(n, arcs, true)).has_value();
}

int main() {
    assert(canFinish(3, {{1, 0}, {2, 1}}));
    assert(!canFinish(2, {{1, 0}, {0, 1}}));
    assert(canFinish(0, {}));
    std::cout << "checks passed\n";
    return 0;
}
