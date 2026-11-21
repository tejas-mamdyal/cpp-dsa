/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Each row lists outgoing destinations. Repeated input edges remain repeated
entries.

Two 0-1 edges create two 1 entries at 0 and two 0 entries at 1.

The constructor appends one incidence for each directed arc or both undirected
incidences.

O(V+E) time and storage; neighbor scan O(degree).

List size measures incidences, not the number of distinct neighbors.
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

int main() {
    auto g = graph(3, {{0, 1}, {0, 1}}, false);
    assert((g[0] == std::vector<int>{1, 1}));
    assert((g[1] == std::vector<int>{0, 0}));
    assert(g[2].empty());
    std::cout << "checks passed\n";
    return 0;
}
