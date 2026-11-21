/*
 At most 8 directed vertices; this is intentionally an enumeration reference. Unless
a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

Use complete backtracking enumeration as an independent small-graph count
baseline; Phase 7 later stores repeated subset states.

Three unconstrained vertices have 3!=6 orders; one complete chain has 1.

Each enumerated complete order contributes exactly one to the count.

Factorial time and saved-order storage; explicitly limited to 8 vertices.

Counting topological orders is not the same as finding one; do not claim linear
complexity.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
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

void enumerate(const Graph& g,
               std::vector<int>& degree,
               std::vector<bool>& used,
               std::vector<int>& path,
               std::vector<std::vector<int>>& out) {
    if (path.size() == g.size()) {
        out.push_back(path);
        return;
    }
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (used[u] || degree[u] != 0) {
            continue;
        }
        used[u] = true;
        path.push_back(u);
        for (int v : g[u]) {
            --degree[v];
        }
        enumerate(g, degree, used, path, out);
        for (int v : g[u]) {
            ++degree[v];
        }
        path.pop_back();
        used[u] = false;
    }
}

std::vector<std::vector<int>> orders(const Graph& g) {
    assert(g.size() <= 8);
    std::vector<int> degree(g.size(), 0);
    for (const auto& row : g) {
        for (int v : row) {
            ++degree[v];
        }
    }
    std::vector<bool> used(g.size(), false);
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    enumerate(g, degree, used, path, out);
    return out;
}

long long countOrders(const Graph& g) {
    return static_cast<long long>(orders(g).size());
}

int main() {
    assert(countOrders(graph(3, {}, true)) == 6);
    assert(countOrders(graph(3, {{0, 1}, {1, 2}}, true)) == 1);
    assert(countOrders(graph(2, {{0, 1}, {1, 0}}, true)) == 0);
    std::cout << "checks passed\n";
    return 0;
}
