/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Each input edge has an ID; the recursive call skips only that ID when
returning to its parent.

Two 0-1 edges: enter throughID 0; the reverse incidence ofID 1 reaches seen 0 and
proves a cycle.

Any nonparent edge reaching a discovered vertex closes an undirected walk without
reusing the entering edge.

O(V+E) time/storage.

Skipping all edges to the parent vertex hides parallel-edge cycles.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstddef>

bool visit(const std::vector<std::vector<std::pair<int, int>>>& g,
           int u,
           int parentEdge,
           std::vector<bool>& seen) {
    seen[u] = true;
    for (auto [v, id] : g[u]) {
        if (id == parentEdge) {
            continue;
        }
        if (seen[v]) {
            return true;
        }
        if (visit(g, v, id, seen)) {
            return true;
        }
    }
    return false;
}

bool cycle(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<std::pair<int, int>>> g(static_cast<std::size_t>(n));
    for (std::size_t i = 0; i < edges.size(); ++i) {
        auto [u, v] = edges[i];
        g[u].emplace_back(v, static_cast<int>(i));
        g[v].emplace_back(u, static_cast<int>(i));
    }
    std::vector<bool> seen(static_cast<std::size_t>(n), false);
    for (int u = 0; u < n; ++u) {
        if (!seen[u] && visit(g, u, -1, seen)) {
            return true;
        }
    }
    return false;
}

int main() {
    assert(!cycle(3, {{0, 1}, {1, 2}}));
    assert(cycle(2, {{0, 1}, {0, 1}}));
    assert(cycle(1, {{0, 0}}));
    assert(!cycle(0, {}));
    std::cout << "checks passed\n";
    return 0;
}
