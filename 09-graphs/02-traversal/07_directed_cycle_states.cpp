/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

State 0 is unseen,1 active on current recursion route,2 finished.

0->1->2->0 reaches active 0 and cycles;2->finished 1 in a DAG is harmless.

A directed back edge to an active ancestor forms a cycle; every cycle exposes one
during DFS.

O(V+E) time, O(V) state/stack.

A single seen flag cannot distinguish these two edge types.
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

bool activeCycle(const Graph& g, int u, std::vector<int>& state) {
    state[u] = 1;
    for (int v : g[u]) {
        if (state[v] == 1) {
            return true;
        }
        if (state[v] == 0 && activeCycle(g, v, state)) {
            return true;
        }
    }
    state[u] = 2;
    return false;
}

bool directedCycle(const Graph& g) {
    std::vector<int> state(g.size(), 0);
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (state[u] == 0 && activeCycle(g, u, state)) {
            return true;
        }
    }
    return false;
}

int main() {
    assert(directedCycle(graph(3, {{0, 1}, {1, 2}, {2, 0}}, true)));
    assert(!directedCycle(graph(3, {{0, 1}, {0, 2}, {2, 1}}, true)));
    assert(!directedCycle({}));
    std::cout << "checks passed\n";
    return 0;
}
