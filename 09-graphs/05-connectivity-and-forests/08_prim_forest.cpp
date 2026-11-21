/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

The heap stores edges leading into unvisited vertices; each new
disconnected root starts with free cost 0.

From 0, choose edge 0-2 cost 1 then 2-1 cost-2; vertex 3 starts a new free
component, total-1.

Every accepted edge is the lightest crossing edge of the current visited cut; the
cut exchange property makes it safe.

O((V+E) log(E+1)) time, O(V+E) storage.

Prim works with negative weights; Dijkstra uses a different nonnegative path proof.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

std::pair<long long, int> prim(const Weighted& g) {
    std::vector<bool> seen(g.size(), false);
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        q;
    long long total = 0;
    int components = 0;
    for (int root = 0; root < static_cast<int>(g.size()); ++root) {
        if (seen[root]) {
            continue;
        }
        ++components;
        q.emplace(0, root);
        while (!q.empty()) {
            auto [weight, u] = q.top();
            q.pop();
            if (seen[u]) {
                continue;
            }
            seen[u] = true;
            total += weight;
            for (auto [v, w] : g[u]) {
                if (!seen[v]) {
                    q.emplace(w, v);
                }
            }
        }
    }
    return {total, components};
}

int main() {
    assert((prim(weighted(4, {{0, 1, 4}, {1, 2, -2}, {0, 2, 1}}, false))
            == std::pair<long long, int>{-1, 2}));
    assert((prim({}) == std::pair<long long, int>{0, 0}));
    std::cout << "checks passed\n";
    return 0;
}
