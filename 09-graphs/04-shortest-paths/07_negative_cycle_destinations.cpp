/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

After V-1 relaxation passes, seed endpoints that can still improve; all
vertices reachable from those seeds are affected.

Cycle 1->2->1 has weight-2 and can repeatedly lower distances to 1,2 and outgoing
3; source 0 and isolated 4 are not affected.

An improving edge witnesses reachability from a negative cycle; any downstream
route can inherit arbitrarily many cycle repetitions.

O(V*E+V+E) time, O(V+E) storage.

Do not mark every graph vertex invalid merely because one reachable negative cycle
exists.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <queue>
#include <cstddef>

struct Edge {
    int from;
    int to;
    int weight;
};

using Weighted = std::vector<std::vector<std::pair<int, int>>>;
constexpr long long INF = std::numeric_limits<long long>::max() / 4;

Weighted weighted(int n, const std::vector<Edge>& edges, bool directed = true) {
    Weighted g(static_cast<std::size_t>(n));
    for (auto e : edges) {
        g[e.from].emplace_back(e.to, e.weight);
        if (!directed) {
            g[e.to].emplace_back(e.from, e.weight);
        }
    }
    return g;
}

std::vector<bool> affected(int n, const std::vector<Edge>& edges, int source) {
    std::vector<long long> d(static_cast<std::size_t>(n), INF);
    d[source] = 0;
    for (int pass = 0; pass < n - 1; ++pass) {
        for (auto e : edges) {
            if (d[e.from] != INF) {
                d[e.to] = std::min(d[e.to], d[e.from] + e.weight);
            }
        }
    }
    std::vector<bool> bad(static_cast<std::size_t>(n), false);
    std::queue<int> q;
    for (auto e : edges) {
        if (d[e.from] != INF && d[e.from] + e.weight < d[e.to] && !bad[e.to]) {
            bad[e.to] = true;
            q.push(e.to);
        }
    }
    auto g = weighted(n, edges);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            (void)w;
            if (!bad[v]) {
                bad[v] = true;
                q.push(v);
            }
        }
    }
    return bad;
}

int main() {
    assert((affected(5, {{0, 1, 1}, {1, 2, -2}, {2, 1, 0}, {2, 3, 1}}, 0)
            == std::vector<bool>{false, true, true, true, false}));
    std::cout << "checks passed\n";
    return 0;
}
