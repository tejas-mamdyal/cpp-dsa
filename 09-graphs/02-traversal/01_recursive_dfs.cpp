/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

seen records completed reachability discovery and stays true across
recursive branches.

0 visits 1 then 2; edge 2->0 is ignored because 0 is already marked;3 follows and
4 stays unreachable.

Every visited vertex has a route from source; every reachable outgoing edge is
examined when its source is visited.

O(V+E) time, O(V) visited/stack/output.

Marking after recursion can loop forever on a cycle.
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

void dfs(const Graph& g, int u, std::vector<bool>& seen, std::vector<int>& order) {
    if (seen[u]) {
        return;
    }
    seen[u] = true;
    order.push_back(u);
    for (int v : g[u]) {
        dfs(g, v, seen, order);
    }
}

int main() {
    auto g = graph(5, {{0, 1}, {1, 2}, {2, 0}, {0, 3}});
    std::vector<bool> seen(5, false);
    std::vector<int> out;
    dfs(g, 0, seen, out);
    assert((out == std::vector<int>{0, 1, 2, 3}));
    assert(!seen[4]);
    std::cout << "checks passed\n";
    return 0;
}
