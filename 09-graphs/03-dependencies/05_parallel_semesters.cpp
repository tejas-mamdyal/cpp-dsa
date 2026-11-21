/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Each current queue snapshot is one semester; newly released courses wait
for the next layer.

Take 0,1 together, then 2, then 3: three semesters.

Every course waits for its longest prerequisite chain; processing all eligible
courses immediately attains that lower bound.

O(V+E) time, O(V) queue/degree.

This assumes unlimited concurrent course capacity and equal one-term durations.
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

std::optional<int> semesters(const Graph& g) {
    std::vector<int> degree(g.size(), 0);
    for (const auto& row : g) {
        for (int v : row) {
            ++degree[v];
        }
    }
    std::queue<int> q;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (degree[u] == 0) {
            q.push(u);
        }
    }
    int terms = 0;
    int taken = 0;
    while (!q.empty()) {
        std::size_t size = q.size();
        ++terms;
        for (std::size_t i = 0; i < size; ++i) {
            int u = q.front();
            q.pop();
            ++taken;
            for (int v : g[u]) {
                --degree[v];
                if (degree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    if (taken != static_cast<int>(g.size())) {
        return std::nullopt;
    }
    return terms;
}

int main() {
    assert(semesters(graph(4, {{0, 2}, {1, 2}, {2, 3}}, true)) == 3);
    assert(semesters({}) == 0);
    assert(!semesters(graph(1, {{0, 0}}, true)));
    std::cout << "checks passed\n";
    return 0;
}
