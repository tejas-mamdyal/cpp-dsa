/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Adjacency entries hold(destination, edge ID), so parallel edges remain
distinguishable in parent-edge traversal.

Two 0-1 edges get IDs 0 and 1; skipping parent edge 0 must not skip edge 1.

One input position assigns one unique ID shared by its two undirected incidences.

O(V+E) construction/storage.

Skipping every edge to the parent vertex can hide a two-edge multigraph cycle.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstddef>

using Multi = std::vector<std::vector<std::pair<int, int>>>;

Multi build(int n, const std::vector<std::pair<int, int>>& edges) {
    Multi g(static_cast<std::size_t>(n));
    for (std::size_t id = 0; id < edges.size(); ++id) {
        auto [u, v] = edges[id];
        g[u].emplace_back(v, static_cast<int>(id));
        g[v].emplace_back(u, static_cast<int>(id));
    }
    return g;
}

int main() {
    auto g = build(2, {{0, 1}, {0, 1}});
    assert((g[0] == std::vector<std::pair<int, int>>{{1, 0}, {1, 1}}));
    assert(g[1].size() == 2);
    std::cout << "checks passed\n";
    return 0;
}
