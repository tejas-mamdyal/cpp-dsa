/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

The BFS vertex includes both original vertex and edge-count parity, as
modeled in unit 1.

0-even reaches 1-odd then 2-even; vertex 1 has no even-length arrival in this
bipartite path.

Each product transition flips parity; BFS first target-even arrival minimizes
valid walk length.

O(V+E) time/storage on the doubled graph.

This asks for a walk, not a simple path; revisiting an original vertex with different
state is permitted.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
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

std::optional<int> evenWalk(const Graph& g, int source, int target) {
    std::vector<int> d(2 * g.size(), -1);
    std::queue<int> q;
    d[2 * source] = 0;
    q.push(2 * source);
    while (!q.empty()) {
        int state = q.front();
        q.pop();
        int u = state / 2;
        int parity = state % 2;
        if (u == target && parity == 0) {
            return d[state];
        }
        for (int v : g[u]) {
            int next = 2 * v + 1 - parity;
            if (d[next] == -1) {
                d[next] = d[state] + 1;
                q.push(next);
            }
        }
    }
    return std::nullopt;
}

int main() {
    auto g = graph(3, {{0, 1}, {1, 2}});
    assert(evenWalk(g, 0, 2) == 2);
    assert(!evenWalk(g, 0, 1));
    assert(evenWalk(g, 0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
