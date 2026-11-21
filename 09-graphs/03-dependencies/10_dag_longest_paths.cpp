/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Use-INF as unreachable and maximize the best value of an incoming
finalized route.

Direct 0->2 gives 1, but 0->1->2 gives 5 and wins.

The same disjoint predecessor recurrence enumerates all DAG routes with max
instead of min.

O(V+E) time/storage.

General longest simple path is not solved by this DAG recurrence.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>
#include <limits>
#include <queue>
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

std::optional<std::vector<int>> topological(const Graph& g) {
    std::vector<int> indegree(g.size(), 0);
    for (const auto& row : g) {
        for (int v : row) {
            ++indegree[v];
        }
    }
    std::queue<int> q;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (indegree[u] == 0) {
            q.push(u);
        }
    }
    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            --indegree[v];
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (order.size() != g.size()) {
        return std::nullopt;
    }
    return order;
}

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

std::optional<std::vector<long long>>
dagDistance(int n, const std::vector<Edge>& edges, int source, bool longest = false) {
    Graph plain(static_cast<std::size_t>(n));
    for (auto e : edges) {
        plain[e.from].push_back(e.to);
    }
    auto order = topological(plain);
    if (!order) {
        return std::nullopt;
    }
    auto g = weighted(n, edges, true);
    long long unreachable = longest ? -INF : INF;
    std::vector<long long> d(static_cast<std::size_t>(n), unreachable);
    d[source] = 0;
    for (int u : *order) {
        if (d[u] == unreachable) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            long long candidate = d[u] + w;
            d[v] = longest ? std::max(d[v], candidate) : std::min(d[v], candidate);
        }
    }
    return d;
}

int main() {
    auto d = dagDistance(4, {{0, 1, 2}, {0, 2, 1}, {1, 2, 3}}, 0, true);
    assert(d && (*d)[2] == 5 && (*d)[3] == -INF);
    std::cout << "checks passed\n";
    return 0;
}
