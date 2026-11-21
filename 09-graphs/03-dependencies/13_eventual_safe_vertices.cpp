/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

outdegree counts successors not yet proven safe; terminal vertices seed
reverse elimination.

Terminal 3 makes 2 safe; cycle 0<->1 never reaches zero residual outdegree.

A vertex is safe exactly when all successors are safe; vertices retaining a path
into a cycle never disappear.

O(V+E) time/storage.

A vertex with one safe branch and one cyclic branch is not eventually safe.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

std::vector<int> safe(const Graph& g) {
    Graph reverse(g.size());
    std::vector<int> degree(g.size(), 0);
    std::queue<int> q;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        degree[u] = static_cast<int>(g[u].size());
        if (degree[u] == 0) {
            q.push(u);
        }
        for (int v : g[u]) {
            reverse[v].push_back(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int p : reverse[u]) {
            --degree[p];
            if (degree[p] == 0) {
                q.push(p);
            }
        }
    }
    std::vector<int> out;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (degree[u] == 0) {
            out.push_back(u);
        }
    }
    return out;
}

int main() {
    assert((safe(graph(4, {{0, 1}, {1, 0}, {2, 3}}, true)) == std::vector<int>{2, 3}));
    assert(safe(graph(1, {{0, 0}}, true)).empty());
    std::cout << "checks passed\n";
    return 0;
}
