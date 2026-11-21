/*
 Undirected multigraph with loops, V<=30; empty graph returns an empty route;
zero-edge nonempty graph returns one vertex.

Stack follows unused edges; when a vertex has none left, append it to the
reversed final route.

Chain 0-1-2 is popped as 2,1,0 and reversed; disconnected loops fail the final
edge-count check.

Splicing exhausted edge walks produces a route using each edge once; degree
conditions ensure at most one open start/end pair.

O(V+E) time/storage.

Degree parity alone does not ensure all nonisolated edges lie on the returned route.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>
#include <cstddef>

std::optional<std::vector<int>> euler(int n, const std::vector<std::pair<int, int>>& edges) {
    if (n == 0) {
        return std::vector<int>{};
    }
    std::vector<std::vector<std::pair<int, int>>> g(static_cast<std::size_t>(n));
    for (std::size_t i = 0; i < edges.size(); ++i) {
        auto [u, v] = edges[i];
        g[u].emplace_back(v, static_cast<int>(i));
        g[v].emplace_back(u, static_cast<int>(i));
    }
    int odd = 0;
    int start = 0;
    for (int u = 0; u < n; ++u) {
        if (!g[u].empty()) {
            start = u;
        }
        if (g[u].size() % 2) {
            ++odd;
        }
    }
    if (odd != 0 && odd != 2) {
        return std::nullopt;
    }
    if (odd == 2) {
        for (int u = 0; u < n; ++u) {
            if (g[u].size() % 2) {
                start = u;
                break;
            }
        }
    }
    std::vector<bool> used(edges.size(), false);
    std::vector<std::size_t> next(static_cast<std::size_t>(n), 0);
    std::vector<int> pending{start};
    std::vector<int> out;
    while (!pending.empty()) {
        int u = pending.back();
        while (next[u] < g[u].size() && used[g[u][next[u]].second]) {
            ++next[u];
        }
        if (next[u] == g[u].size()) {
            out.push_back(u);
            pending.pop_back();
        } else {
            auto [v, id] = g[u][next[u]];
            ++next[u];
            used[id] = true;
            pending.push_back(v);
        }
    }
    if (out.size() != edges.size() + 1) {
        return std::nullopt;
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    auto path = euler(3, {{0, 1}, {1, 2}});
    assert(path && path->size() == 3);
    assert(euler(1, {{0, 0}})->size() == 2);
    assert(!euler(2, {{0, 0}, {1, 1}}));
    assert(!euler(4, {{0, 1}, {0, 2}, {0, 3}}));
    std::cout << "checks passed\n";
    return 0;
}
