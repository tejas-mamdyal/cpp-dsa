/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

parent is set only on first discovery.

Target 2 follows 2->1->0 before reversal.

BFS discovers shortest layers and each parent precedes its child by one layer.

O(V+E) time, O(V) auxiliary plus route.

A valid endpoint alone does not validate every route edge.
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

std::vector<int> route(const Graph& g, int source, int target) {
    std::vector<int> parent(g.size(), -1);
    std::queue<int> q;
    parent[source] = source;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if (parent[target] == -1) {
        return {};
    }
    std::vector<int> out;
    for (int at = target;; at = parent[at]) {
        out.push_back(at);
        if (at == source) {
            break;
        }
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    assert((route(graph(4, {{0, 1}, {1, 2}}), 0, 2) == std::vector<int>{0, 1, 2}));
    assert(route(graph(4, {}), 0, 3).empty());
    std::cout << "checks passed\n";
    return 0;
}
