/*
 Directed graph with at most 8 vertices.

used, path, and mutable indegrees describe the residual dependency
problem; undo all three after a branch.

Choose 0 then 1 then 2; undo 0 branch, choose 1 then 0 then 2.

Every valid order chooses an indegree-zero unused vertex at each position; all
such choices are explored once.

O((V+E)*V!) upper-bound time, O(V+E) work plus output.

Restoring used without restoring indegrees contaminates later branches.
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

void enumerate(const Graph& g,
               std::vector<int>& degree,
               std::vector<bool>& used,
               std::vector<int>& path,
               std::vector<std::vector<int>>& out) {
    if (path.size() == g.size()) {
        out.push_back(path);
        return;
    }
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (used[u] || degree[u] != 0) {
            continue;
        }
        used[u] = true;
        path.push_back(u);
        for (int v : g[u]) {
            --degree[v];
        }
        enumerate(g, degree, used, path, out);
        for (int v : g[u]) {
            ++degree[v];
        }
        path.pop_back();
        used[u] = false;
    }
}

std::vector<std::vector<int>> orders(const Graph& g) {
    assert(g.size() <= 8);
    std::vector<int> degree(g.size(), 0);
    for (const auto& row : g) {
        for (int v : row) {
            ++degree[v];
        }
    }
    std::vector<bool> used(g.size(), false);
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    enumerate(g, degree, used, path, out);
    return out;
}

int main() {
    assert((orders(graph(3, {{0, 2}, {1, 2}}, true))
            == std::vector<std::vector<int>>{{0, 1, 2}, {1, 0, 2}}));
    assert(orders(graph(1, {{0, 0}}, true)).empty());
    assert(orders({}).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
