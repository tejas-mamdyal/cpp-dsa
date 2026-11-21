/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

The vertex count is independent of the number of endpoint labels appearing
in edges. A touched array identifies isolated vertices.

n 4, edges 0-1 and 1-2 touch three vertices; vertex 3 is isolated.

A vertex is isolated exactly when no edge endpoint touches it.

O(V+E) time, O(V) auxiliary storage.

Inferring n from the largest endpoint loses trailing isolated vertices.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

int isolated(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<bool> touched(static_cast<std::size_t>(n), false);
    for (auto [u, v] : edges) {
        touched[u] = true;
        touched[v] = true;
    }
    return static_cast<int>(std::count(touched.begin(), touched.end(), false));
}

int main() {
    assert(isolated(4, {{0, 1}, {1, 2}}) == 1);
    assert(isolated(0, {}) == 0);
    auto g = graph(4, {{0, 1}});
    assert(g.size() == 4 && g[3].empty());
    std::cout << "checks passed\n";
    return 0;
}
