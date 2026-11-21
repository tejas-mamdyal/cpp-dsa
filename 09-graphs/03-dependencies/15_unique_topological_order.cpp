/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Record whether Kahn ever has two eligible vertices; separately reject a
cyclic residual graph.

A chain always has one choice; two independent prerequisites can be swapped and
give two orders.

Two ready vertices can exchange their next positions; one ready choice at every
step forces the entire order.

O(V+E) time, O(V) auxiliary.

False uniqueness and no valid order are different outcomes; optional distinguishes
them.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
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

std::optional<bool> uniqueOrder(const Graph& g) {
    std::vector<int> degree(g.size(), 0);
    for (const auto& row : g) {
        for (int v : row) {
            ++degree[v];
        }
    }
    std::queue<int> q;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (degree[u] == 0) {
            q.push(u);
        }
    }
    bool unique = true;
    int count = 0;
    while (!q.empty()) {
        if (q.size() != 1) {
            unique = false;
        }
        int u = q.front();
        q.pop();
        ++count;
        for (int v : g[u]) {
            --degree[v];
            if (degree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (count != static_cast<int>(g.size())) {
        return std::nullopt;
    }
    return unique;
}

int main() {
    assert(uniqueOrder(graph(3, {{0, 1}, {1, 2}}, true)) == true);
    assert(uniqueOrder(graph(3, {{0, 2}, {1, 2}}, true)) == false);
    assert(!uniqueOrder(graph(1, {{0, 0}}, true)));
    assert(uniqueOrder({}) == true);
    std::cout << "checks passed\n";
    return 0;
}
