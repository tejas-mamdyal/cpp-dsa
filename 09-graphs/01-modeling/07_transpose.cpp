/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

The reversed row v receives u for every original u->v.

0->1 and 2->1 become 1->0 and 1->2.

Reversing endpoint order twice restores every original arc and multiplicity.

O(V+E) time/storage.

Transposition does not mean reversing the order of each adjacency vector.
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

Graph transpose(const Graph& g) {
    Graph reversed(g.size());
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        for (int v : g[u]) {
            reversed[v].push_back(u);
        }
    }
    return reversed;
}

int main() {
    auto g = graph(3, {{0, 1}, {2, 1}}, true);
    auto r = transpose(g);
    assert((r[1] == std::vector<int>{0, 2}));
    assert(r[0].empty());
    auto twice = transpose(r);
    for (auto& row : twice) {
        std::sort(row.begin(), row.end());
    }
    assert(twice == g);
    std::cout << "checks passed\n";
    return 0;
}
