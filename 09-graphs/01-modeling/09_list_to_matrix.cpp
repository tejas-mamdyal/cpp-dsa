/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Set matrix entries for existing arcs; preserve vertices but intentionally
collapse repeated arcs.

Row 0=[1,1] becomes one true matrix entry.

The converted boolean matrix preserves exactly the arc-existence relation.

O(V^2+E) time, O(V^2) result.

This conversion is not reversible if parallel-edge multiplicity matters.
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

std::vector<std::vector<bool>> convert(const Graph& g) {
    std::vector<std::vector<bool>> a(g.size(), std::vector<bool>(g.size(), false));
    for (std::size_t u = 0; u < g.size(); ++u) {
        for (int v : g[u]) {
            a[u][v] = true;
        }
    }
    return a;
}

int main() {
    auto a = convert(graph(3, {{0, 1}, {0, 1}, {1, 2}}, true));
    assert(a[0][1] && a[1][2] && !a[0][2]);
    assert(a.size() == 3);
    std::cout << "checks passed\n";
    return 0;
}
