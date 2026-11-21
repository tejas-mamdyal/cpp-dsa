/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

The explicit stack contains candidate future visits; stale duplicate
candidates are ignored when popped.

Push neighbors 2 then 1 so 1 pops before 2; its child 3 completes first.

The stack preserves depth-first pending work; seen prevents repeating output for
a vertex.

O(V+E) time, O(V+E) possible pending entries in this mark-on-pop baseline.

Do not claim O(V) pending storage when duplicate stack candidates are allowed.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <stack>
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

std::vector<int> dfs(const Graph& g, int start) {
    std::vector<bool> seen(g.size(), false);
    std::vector<int> out;
    std::stack<int> pending;
    pending.push(start);
    while (!pending.empty()) {
        int u = pending.top();
        pending.pop();
        if (seen[u]) {
            continue;
        }
        seen[u] = true;
        out.push_back(u);
        for (auto it = g[u].rbegin(); it != g[u].rend(); ++it) {
            if (!seen[*it]) {
                pending.push(*it);
            }
        }
    }
    return out;
}

int main() {
    assert((dfs(graph(4, {{0, 1}, {0, 2}, {1, 3}}), 0) == std::vector<int>{0, 1, 3, 2}));
    assert(dfs(graph(1, {}), 0) == std::vector<int>{0});
    std::cout << "checks passed\n";
    return 0;
}
