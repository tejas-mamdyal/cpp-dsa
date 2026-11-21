/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Assign 0/1 colors by BFS, starting every component independently.

A square alternates 0,1,0,1; closing a triangle forces equal colors across an
edge.

Each assignment satisfies its discovery edge; checking all edges certifies a
two-coloring or a conflict.

O(V+E) time, O(V) storage.

Disconnected components and self-loops must be checked too.
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

std::optional<std::vector<int>> bipartite(const Graph& g) {
    std::vector<int> color(g.size(), -1);
    for (int root = 0; root < static_cast<int>(g.size()); ++root) {
        if (color[root] != -1) {
            continue;
        }
        std::queue<int> q;
        color[root] = 0;
        q.push(root);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return std::nullopt;
                }
            }
        }
    }
    return color;
}

int main() {
    assert(bipartite(graph(4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}})));
    assert(!bipartite(graph(3, {{0, 1}, {1, 2}, {2, 0}})));
    assert(!bipartite(graph(1, {{0, 0}})));
    std::cout << "checks passed\n";
    return 0;
}
