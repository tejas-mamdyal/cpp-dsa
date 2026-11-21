/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

Each undirected edge requires opposite colors.

A triangle forces a color conflict on its third edge.

Consistent two-coloring exists exactly when no odd cycle contradicts parity.

O(V+E) time/storage.

Checking only the component containing 0 misses disconnected conflicts.
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

bool bipartite(const Graph& g) {
    std::vector<int> color(g.size(), -1);
    for (int start = 0; start < static_cast<int>(g.size()); ++start) {
        if (color[start] != -1) {
            continue;
        }
        std::queue<int> q;
        color[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    assert(bipartite(graph(4, {{0, 1}, {2, 3}})));
    assert(!bipartite(graph(3, {{0, 1}, {1, 2}, {2, 0}})));
    std::cout << "checks passed\n";
    return 0;
}
