/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Global seen partitions an undirected graph into maximal reachable groups.

Edges 0-1 and 2-3 with isolated 4 yield three roots of new traversals.

Each traversal covers exactly one undirected component, and no later root belongs
to it.

O(V+E) time, O(V) stack/visited.

Directed weak/strong connectivity are different definitions; this lesson is
undirected.
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

int components(const Graph& g) {
    std::vector<bool> seen(g.size(), false);
    int count = 0;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (!seen[u]) {
            std::vector<int> out;
            dfs(g, u, seen, out);
            ++count;
        }
    }
    return count;
}

int main() {
    assert(components(graph(5, {{0, 1}, {2, 3}})) == 3);
    assert(components(graph(0, {})) == 0);
    std::cout << "checks passed\n";
    return 0;
}
