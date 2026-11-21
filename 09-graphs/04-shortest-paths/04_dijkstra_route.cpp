/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Maintain a predecessor alongside each improved tentative value; ties leave
the existing witness unchanged.

Vertex 1 parent changes from 0 to 2 when cost 8 improves to 3.

Every strict parent update corresponds to a real improving route; nonnegative
Dijkstra certifies its final value.

O((V+E) log(E+1)) time, O(V+E) work plus route.

Blind equal-distance parent rewrites on zero-cost cycles can create reconstruction
cycles.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>
#include <limits>
#include <queue>
#include <functional>
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

std::optional<std::pair<long long, std::vector<int>>>
route(const Weighted& g, int source, int target) {
    std::vector<long long> d(g.size(), INF);
    std::vector<int> parent(g.size(), -1);
    std::priority_queue<std::pair<long long, int>,
                        std::vector<std::pair<long long, int>>,
                        std::greater<std::pair<long long, int>>>
        q;
    d[source] = 0;
    q.emplace(0, source);
    while (!q.empty()) {
        auto [snapshot, u] = q.top();
        q.pop();
        if (snapshot != d[u]) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            assert(w >= 0);
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                parent[v] = u;
                q.emplace(d[v], v);
            }
        }
    }
    if (d[target] == INF) {
        return std::nullopt;
    }
    std::vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return std::pair<long long, std::vector<int>>{d[target], path};
}

int main() {
    auto answer = route(weighted(3, {{0, 1, 8}, {0, 2, 1}, {2, 1, 2}}), 0, 1);
    assert(answer && answer->first == 3 && (answer->second == std::vector<int>{0, 2, 1}));
    assert(!route(weighted(2, {}), 0, 1));
    std::cout << "checks passed\n";
    return 0;
}
