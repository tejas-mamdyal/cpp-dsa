/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

The ready frontier is a min-heap, so choose the smallest currently legal
next vertex.

Initially 1,2 ready; choose 1, which releases 0; choose 0 before 2.

Any valid order must choose an eligible vertex; choosing the smallest minimizes
the first differing position recursively.

O((V+E) log(V+1)) upper-bound time, O(V) work.

A FIFO Kahn queue is valid but need not be lexicographically smallest.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <queue>
#include <functional>
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

std::optional<std::vector<int>> lexical(const Graph& g) {
    std::vector<int> degree(g.size(), 0);
    for (const auto& row : g) {
        for (int v : row) {
            ++degree[v];
        }
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (degree[u] == 0) {
            q.push(u);
        }
    }
    std::vector<int> out;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        out.push_back(u);
        for (int v : g[u]) {
            --degree[v];
            if (degree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (out.size() != g.size()) {
        return std::nullopt;
    }
    return out;
}

int main() {
    assert((lexical(graph(3, {{1, 0}}, true)) == std::optional<std::vector<int>>{{1, 0, 2}}));
    assert(!lexical(graph(1, {{0, 0}}, true)));
    std::cout << "checks passed\n";
    return 0;
}
