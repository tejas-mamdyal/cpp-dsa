/*
 Connected undirected unweighted tree; empty tree convention 0. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

First traversal finds a peripheral endpoint; second measures its farthest
distance.

2-1-3-4 is a 3-edge diameter.

Unique tree routes imply a farthest vertex from any start is an endpoint of some
diameter; the second sweep attains it.

O(V+E) time/storage.

Two sweeps are not an exact general-graph diameter algorithm.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

std::vector<int> distances(const Graph& g, int source) {
    assert(source >= 0 && source < static_cast<int>(g.size()));
    std::vector<int> d(g.size(), -1);
    std::queue<int> q;
    d[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[v] != -1) {
                continue;
            }
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    return d;
}

int diameter(const Graph& g) {
    if (g.empty()) {
        return 0;
    }
    auto first = distances(g, 0);
    int endpoint = static_cast<int>(std::max_element(first.begin(), first.end()) - first.begin());
    auto second = distances(g, endpoint);
    return *std::max_element(second.begin(), second.end());
}

int main() {
    assert(diameter(graph(5, {{0, 1}, {1, 2}, {1, 3}, {3, 4}})) == 3);
    assert(diameter(graph(1, {})) == 0);
    std::cout << "checks passed\n";
    return 0;
}
