/*
COMPOSE TWO 2^(J-1) JUMPS INTO ONE 2^J JUMP

 Valid nonempty tree<=30, root 0; valid vertices, steps may be invalid and return
absence.

up[j][u] is the 2^j-th ancestor with root self-saturation internally; the
public method rejects requests beyond actual depth.

Three steps from 4 split into a two-step jump to 2 and a one-step jump to 1.

Ancestor composition is associative; binary expansion of steps combines disjoint
powers to exactly the requested length.

O(V log V) build, O(log V) query, O(V log V) storage.

Root saturation is a table convenience, not permission to answer out-of-depth queries
as root.
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
};

int main() {
    Lifting l(graph(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}));
    assert(l.ancestor(4, 3) == 1);
    assert(l.ancestor(0, 0) == 0);
    assert(!l.ancestor(2, 3));
    std::cout << "checks passed\n";
    return 0;
}
