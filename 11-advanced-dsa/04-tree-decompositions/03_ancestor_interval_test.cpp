/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

An ancestor interval contains every descendant entry rank; self ancestry
is included by convention.

tin 4 lies inside[tin 1, tout 1), but not inside subtree 2.

Rooted subtrees are nested for ancestor pairs and disjoint for unrelated
branches.

O(V) preprocessing, O(1) query, O(V) storage.

Use strict upper bound tin[v]<tout[u] for half-open intervals.
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
    Euler e(graph(5, {{0, 1}, {0, 2}, {1, 3}, {1, 4}}));
    assert(e.ancestor(1, 4));
    assert(!e.ancestor(2, 4));
    assert(e.ancestor(3, 3));
    std::cout << "checks passed\n";
    return 0;
}
