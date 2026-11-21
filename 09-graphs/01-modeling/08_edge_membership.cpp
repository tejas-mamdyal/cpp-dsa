/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Linear search in one unsorted adjacency row is a simple baseline; matrix
membership is constant-time at quadratic storage cost.

Searching row 0=[1] finds 1 but not 2; searching row 1 finds no reverse arc.

Membership is exactly presence of v among u outgoing entries.

O(outdegree(u)) query, O(1) auxiliary.

An adjacency list lookup is not automatically O(1).
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

bool edge(const Graph& g, int u, int v) {
    return std::find(g[u].begin(), g[u].end(), v) != g[u].end();
}

int main() {
    auto g = graph(3, {{0, 1}}, true);
    assert(edge(g, 0, 1));
    assert(!edge(g, 1, 0));
    assert(!edge(g, 0, 2));
    std::cout << "checks passed\n";
    return 0;
}
