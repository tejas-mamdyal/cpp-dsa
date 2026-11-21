/*
 Nonnegative task durations, one per vertex; dependency graph may be rejected if
cyclic.

finish[v] is earliest possible completion with unlimited parallel
resources; each predecessor may delay its start.

Tasks 0 and 1 finish at 3 and 5; task 2 lasts 2 and finishes at 7.

A task cannot start until its latest prerequisite finishes; topological
processing makes all those bounds final and attainable.

O(V+E) time, O(V) states.

Resource-limited scheduling is a different optimization problem.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

std::optional<long long> completion(const Graph& g, const std::vector<int>& duration) {
    auto order = topological(g);
    if (!order) {
        return std::nullopt;
    }
    std::vector<long long> finish(duration.begin(), duration.end());
    long long total = 0;
    for (int u : *order) {
        total = std::max(total, finish[u]);
        for (int v : g[u]) {
            finish[v] = std::max(finish[v], finish[u] + duration[v]);
        }
    }
    return total;
}

int main() {
    assert(completion(graph(3, {{0, 2}, {1, 2}}, true), {3, 5, 2}) == 7);
    assert(completion({}, {}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
