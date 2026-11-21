/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Add a temporary vertex with zero-weight arcs to all starts, then discard
its output distance.

Starts 0 and 2 compete for 1; cost 1 from 2 beats cost 4 from 0, and 3 gets 3.

Every super-source route selects exactly one original start with no added cost.

O((V+E+S) log(E+S+1)) time and copied graph storage.

Super-source arcs must be directed outward; adding reverse arcs can create artificial
shortcuts.
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

std::vector<long long> dijkstra(const Weighted& g, int source) {
    std::vector<long long> d(g.size(), INF);
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
                q.emplace(d[v], v);
            }
        }
    }
    return d;
}

std::vector<long long> multi(const Weighted& input, const std::vector<int>& sources) {
    auto g = input;
    g.push_back({});
    int source = static_cast<int>(input.size());
    for (int s : sources) {
        g[source].emplace_back(s, 0);
    }
    auto d = dijkstra(g, source);
    d.pop_back();
    return d;
}

int main() {
    auto g = weighted(4, {{0, 1, 4}, {2, 1, 1}, {1, 3, 2}});
    assert((multi(g, {0, 2}) == std::vector<long long>{0, 1, 0, 3}));
    assert(multi(g, {}) == std::vector<long long>({INF, INF, INF, INF}));
    std::cout << "checks passed\n";
    return 0;
}
