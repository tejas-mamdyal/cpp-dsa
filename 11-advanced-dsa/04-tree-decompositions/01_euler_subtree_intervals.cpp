/*
 Valid undirected tree, V 1..30, root 0; adjacency order determines entry order.

tin[u] is its entry rank; tout[u] is the first rank after all descendants;
order lists each vertex once.

Tree 0 children 1,2 and 1 children 3,4 gives order 0,1,3,4,2; subtree 1
occupies[1,4).

DFS completes every descendant before returning to u parent, so no outside vertex
interrupts its entry interval.

O(V) time/storage and O(height) recursion.

This entry-only array differs from a repeated Euler walk used in some LCA RMQ
algorithms.
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

class Euler {
    Graph g;

    void visit(int u, int p) {
        parent[u] = p;
        tin[u] = static_cast<int>(order.size());
        order.push_back(u);
        for (int v : g[u]) {
            if (v == p) {
                continue;
            }
            depth[v] = depth[u] + 1;
            visit(v, u);
        }
        tout[u] = static_cast<int>(order.size());
    }

public:
    std::vector<int> tin;
    std::vector<int> tout;
    std::vector<int> depth;
    std::vector<int> parent;
    std::vector<int> order;

    explicit Euler(const Graph& input)
        : g(input),
          tin(g.size()),
          tout(g.size()),
          depth(g.size(), 0),
          parent(g.size(), -1) {
        if (!g.empty()) {
            visit(0, -1);
        }
    }

    bool ancestor(int u, int v) const {
        return tin[u] <= tin[v] && tin[v] < tout[u];
    }
};

int main() {
    auto g = graph(5, {{0, 1}, {0, 2}, {1, 3}, {1, 4}});
    Euler e(g);
    assert((e.order == std::vector<int>{0, 1, 3, 4, 2}));
    assert(e.tin[1] == 1 && e.tout[1] == 4);
    assert(e.tout[0] == 5);
    std::cout << "checks passed\n";
    return 0;
}
