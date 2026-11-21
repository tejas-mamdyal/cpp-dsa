/*
 Nonempty undirected graph and valid source; return any farthest reachable vertex.

Distances distinguish unreachable -1 from finite BFS layers.

Vertex 2 is 2 hops away; isolated 4 is excluded.

BFS first discoveries minimize hop counts; max over finite labels gives component
eccentricity.

O(V+E) time/storage.

This is component eccentricity, not a finite diameter of a disconnected graph.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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
    int farthest = static_cast<int>(std::max_element(d.begin(), d.end()) - d.begin());
    assert(farthest == 2 && d[farthest] == 2 && d[4] == -1);
    std::cout << "checks passed\n";
    return 0;
}
