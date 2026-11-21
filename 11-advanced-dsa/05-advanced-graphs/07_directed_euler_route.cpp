/*
REQUIRE MATCHING INCOMING/OUTGOING BALANCE EXCEPT TWO ENDPOINTS

 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

A trail start may have out-in 1, end in-out 1; all others balance. Each
adjacency entry is one directed edge to consume.

0->1->2 has one start surplus at 0 and one end deficit at 2.

Every internal visit consumes matching entry/exit arcs; Hierholzer consumes all
arcs under those balances when the final witness has E+1 vertices.

O(V+E) time/storage.

A balanced disconnected collection of cycles is not one Euler circuit.
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
    std::vector<std::vector<int>> g(static_cast<std::size_t>(n));
    std::vector<int> in(static_cast<std::size_t>(n), 0);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        ++in[v];
    }
    int start = 0;
    int positive = 0;
    int negative = 0;
    for (int u = 0; u < n; ++u) {
        int diff = static_cast<int>(g[u].size()) - in[u];
        if (diff == 1) {
            ++positive;
            start = u;
        } else if (diff == -1) {
            ++negative;
        } else if (diff != 0) {
            return std::nullopt;
        }
    }
    if (positive != negative || positive > 1) {
        return std::nullopt;
    }
    if (positive == 0) {
        for (int u = 0; u < n; ++u) {
            if (!g[u].empty()) {
                start = u;
                break;
            }
        }
    }
    std::vector<std::size_t> next(static_cast<std::size_t>(n), 0);
    std::vector<int> pending{start};
    std::vector<int> out;
    while (!pending.empty()) {
        int u = pending.back();
        if (next[u] == g[u].size()) {
            out.push_back(u);
            pending.pop_back();
        } else {
            int v = g[u][next[u]];
            ++next[u];
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
    assert((euler(3, {{0, 1}, {1, 2}}) == std::optional<std::vector<int>>{{0, 1, 2}}));
    assert(!euler(3, {{0, 1}, {0, 2}}));
    assert(!euler(2, {{0, 0}, {1, 1}}));
    std::cout << "checks passed\n";
    return 0;
}
