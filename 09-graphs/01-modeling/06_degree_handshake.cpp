/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Both endpoints of each undirected edge contribute an incidence, including
two incidences of a loop at the same vertex.

Two 0-1 edges plus loop 1-1 give degrees 2,4,0, total 6=2E.

Sum degree counts every edge exactly twice.

O(V+E) time and stored incidences.

Adding a self-loop only once breaks the usual undirected degree convention.
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
    auto g = graph(3, {{0, 1}, {1, 1}, {0, 1}}, false);
    long long sum = 0;
    for (const auto& row : g) {
        sum += static_cast<long long>(row.size());
    }
    assert(sum == 6);
    assert(g[1].size() == 4);
    assert(g[2].empty());
    std::cout << "checks passed\n";
    return 0;
}
