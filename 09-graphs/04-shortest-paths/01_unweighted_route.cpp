/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

parent is set on first BFS discovery; the source parents itself to
terminate reconstruction.

Direct 0->2 discovers 2 before the longer 0->1->2 route can change its parent.

BFS first discovery minimizes edge count; parent links follow one such route back
to source.

O(V+E) time, O(V) work/path.

Unreachable targets must return absence instead of following parent-1.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

std::optional<std::vector<int>> shortestPath(const Graph& g, int source, int target) {
    std::vector<int> parent(g.size(), -1);
    std::queue<int> q;
    parent[source] = source;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if (parent[target] == -1) {
        return std::nullopt;
    }
    std::vector<int> path;
    for (int v = target; v != source; v = parent[v]) {
        path.push_back(v);
    }
    path.push_back(source);
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    assert((shortestPath(graph(4, {{0, 1}, {1, 2}, {0, 2}}), 0, 2)
            == std::optional<std::vector<int>>{{0, 2}}));
    assert(!shortestPath(graph(3, {}), 0, 2));
    assert((shortestPath(graph(1, {}), 0, 0) == std::optional<std::vector<int>>{{0}}));
    std::cout << "checks passed\n";
    return 0;
}
