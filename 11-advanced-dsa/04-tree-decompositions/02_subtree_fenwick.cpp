/*
 Valid nonempty rooted tree<=30 with one signed value per vertex. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

Fenwick position tin[u] stores vertex u value; subtree sum uses[tin[u],
tout[u]).

Subtree 1 values 2,4,5 total 11; changing 5 to-5 lowers it to 1.

The Euler interval contains exactly subtree vertices, and each point update
changes exactly its stored contribution.

O(V log V) build, O(log V) point update/subtree query, O(V) storage.

External vertex IDs are not necessarily their Euler positions.
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

class Fenwick {
    std::vector<long long> bit;

    static std::size_t lowbit(std::size_t i) {
        return i & (~i + std::size_t{1});
    }

public:
    explicit Fenwick(std::size_t n)
        : bit(n + 1, 0) {
    }

    void add(std::size_t index, long long delta) {
        assert(index + 1 < bit.size());
        for (std::size_t i = index + 1; i < bit.size(); i += lowbit(i)) {
            bit[i] += delta;
        }
    }

    long long prefix(std::size_t end) const {
        assert(end < bit.size());
        long long sum = 0;
        for (std::size_t i = end; i > 0; i -= lowbit(i)) {
            sum += bit[i];
        }
        return sum;
    }

    long long range(std::size_t left, std::size_t right) const {
        assert(left <= right);
        return prefix(right) - prefix(left);
    }
};

class Subtrees {
    Euler tour;
    Fenwick bit;
    std::vector<int> value;

public:
    Subtrees(const Graph& g, const std::vector<int>& a)
        : tour(g),
          bit(g.size()),
          value(a) {
        for (std::size_t u = 0; u < g.size(); ++u) {
            bit.add(static_cast<std::size_t>(tour.tin[u]), a[u]);
        }
    }

    void set(int u, int x) {
        bit.add(static_cast<std::size_t>(tour.tin[u]), x - value[u]);
        value[u] = x;
    }

    long long sum(int u) const {
        return bit.range(static_cast<std::size_t>(tour.tin[u]),
                         static_cast<std::size_t>(tour.tout[u]));
    }
};

int main() {
    Subtrees s(graph(5, {{0, 1}, {0, 2}, {1, 3}, {1, 4}}), {1, 2, 3, 4, 5});
    assert(s.sum(1) == 11);
    s.set(4, -5);
    assert(s.sum(1) == 1 && s.sum(0) == 5);
    std::cout << "checks passed\n";
    return 0;
}
