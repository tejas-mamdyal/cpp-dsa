/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Seed each distinct source at distance 0; the queue interleaves all source
layers.

On a five-node chain, ends 0 and 4 give distances 0,1,2,1,0.

First discovery is the shortest route from the union of all source roots.

O(V+E+number sources) time, O(V) work.

Repeated sources must not repeatedly enqueue the same initial state.
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

std::vector<int> multiple(const Graph& g, const std::vector<int>& sources) {
    std::vector<int> d(g.size(), -1);
    std::queue<int> q;
    for (int s : sources) {
        if (d[s] == -1) {
            d[s] = 0;
            q.push(s);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d;
}

int main() {
    assert((multiple(graph(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}), {0, 4, 0})
            == std::vector<int>{0, 1, 2, 1, 0}));
    assert(multiple(graph(2, {}), {}) == std::vector<int>({-1, -1}));
    std::cout << "checks passed\n";
    return 0;
}
