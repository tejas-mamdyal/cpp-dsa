/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Distance-1 means undiscovered; source 0 begins layer 0; mark the distance
before enqueueing a neighbor.

0 discovers 1 and 3 at distance 1;1 discovers 2 at 2; isolated 4 stays-1.

FIFO processes all shorter layers before a new layer, so first discovery uses a
minimum-edge route.

O(V+E) time, O(V) distance/queue.

This optimizes edge count only when all moves have equal cost.
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

std::vector<int> distances(const Graph& g, int source) {
    assert(source >= 0 && source < static_cast<int>(g.size()));
    std::vector<int> d(g.size(), -1);
    std::queue<int> q;
    d[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[v] != -1) {
                continue;
            }
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    return d;
}

int main() {
    auto d = distances(graph(5, {{0, 1}, {1, 2}, {0, 3}}), 0);
    assert((d == std::vector<int>{0, 1, 2, 1, -1}));
    std::cout << "checks passed\n";
    return 0;
}
