/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

id-1 means unassigned; each BFS root assigns one deterministic scan-order
component number.

Root 0 labels 0,2 with 0; root 1 labels 1,3 with 1; vertex 4 gets 2.

Only reachable neighbors share one root label, and every vertex receives one
label.

O(V+E) time, O(V) storage.

Component numbers depend on traversal roots; compare membership rather than arbitrary
label values across algorithms.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

std::vector<int> labels(const Graph& g) {
    std::vector<int> id(g.size(), -1);
    int component = 0;
    for (int root = 0; root < static_cast<int>(g.size()); ++root) {
        if (id[root] != -1) {
            continue;
        }
        std::queue<int> q;
        q.push(root);
        id[root] = component;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (id[v] == -1) {
                    id[v] = component;
                    q.push(v);
                }
            }
        }
        ++component;
    }
    return id;
}

int main() {
    auto id = labels(graph(5, {{0, 2}, {1, 3}}));
    assert((id == std::vector<int>{0, 1, 0, 1, 2}));
    std::vector<int> sizes(3, 0);
    for (int x : id) {
        ++sizes[x];
    }
    assert((sizes == std::vector<int>{2, 2, 1}));
    std::cout << "checks passed\n";
    return 0;
}
