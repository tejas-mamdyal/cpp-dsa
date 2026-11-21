/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Equalize depths, then consider jumps descending by powers; accept a jump
only if the two ancestors remain different.

Nodes 3 and 4 cannot move above their equal parent 1; the final parent is 1.

After depth alignment, the LCA is unchanged; paired unequal jumps remain strictly
below it, and maximal lifting leaves the two children immediately below it.

O(V log V) preprocessing, O(log V) query/storage O(V log V).

The input must be a valid connected tree; general DAG vertices can have multiple
incomparable common ancestors.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
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

class Lifting {
    Euler tour;
    std::vector<std::vector<int>> up;

public:
    std::vector<int> depth;

    explicit Lifting(const Graph& g)
        : tour(g),
          depth(tour.depth) {
        int levels = 1;
        while ((1U << levels) <= g.size()) {
            ++levels;
        }
        up.assign(static_cast<std::size_t>(levels), std::vector<int>(g.size(), 0));
        for (std::size_t u = 0; u < g.size(); ++u) {
            up[0][u] = tour.parent[u] < 0 ? static_cast<int>(u) : tour.parent[u];
        }
        for (int level = 1; level < levels; ++level) {
            for (std::size_t u = 0; u < g.size(); ++u) {
                up[level][u] = up[level - 1][up[level - 1][u]];
            }
        }
    }

    std::optional<int> ancestor(int u, int steps) const {
        if (steps < 0 || steps > depth[u]) {
            return std::nullopt;
        }
        for (std::size_t bit = 0; bit < up.size(); ++bit) {
            if (static_cast<unsigned int>(steps) & (1U << bit)) {
                u = up[bit][u];
            }
        }
        return u;
    }

    int lca(int u, int v) const {
        if (depth[u] < depth[v]) {
            std::swap(u, v);
        }
        u = *ancestor(u, depth[u] - depth[v]);
        if (u == v) {
            return u;
        }
        for (int level = static_cast<int>(up.size()) - 1; level >= 0; --level) {
            if (up[level][u] != up[level][v]) {
                u = up[level][u];
                v = up[level][v];
            }
        }
        return up[0][u];
    }
};

int main() {
    Lifting l(graph(5, {{0, 1}, {0, 2}, {1, 3}, {1, 4}}));
    assert(l.lca(3, 4) == 1);
    assert(l.lca(3, 2) == 0);
    assert(l.lca(1, 1) == 1);
    std::cout << "checks passed\n";
    return 0;
}
