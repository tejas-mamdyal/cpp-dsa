/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Outdegree is row length; indegree accumulates arrivals from every row.

0->1,0->2,2->1 give vertex 1 indegree 2 and outdegree 0.

Every arc contributes once to its source outgoing count and destination incoming
count.

O(V+E) time, O(V) returned counts.

Undirected degree formulas cannot replace directed in/out counts.
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

std::pair<std::vector<int>, std::vector<int>> degrees(const Graph& g) {
    std::vector<int> in(g.size(), 0);
    std::vector<int> out(g.size(), 0);
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        out[u] = static_cast<int>(g[u].size());
        for (int v : g[u]) {
            ++in[v];
        }
    }
    return {in, out};
}

int main() {
    auto [in, out] = degrees(graph(3, {{0, 1}, {0, 2}, {2, 1}}, true));
    assert((in == std::vector<int>{0, 2, 1}));
    assert((out == std::vector<int>{2, 0, 1}));
    std::cout << "checks passed\n";
    return 0;
}
