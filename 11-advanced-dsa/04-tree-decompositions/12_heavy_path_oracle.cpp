/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Maintain an independent value vector; BFS parent routes identify the exact
path without using heavy-chain positions.

Each update changes one original vertex; all 64 source-target sums are checked
after every update.

A tree has one connecting route, so its directly summed BFS witness independently
specifies each expected node-path total.

Diagnostic O(updates*V^2) path work on this tiny tree, plus heavy query costs.

Testing only one final route may miss chain-head and LCA boundary errors.
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

class HeavyPaths {
    Graph g;
    std::vector<int> parent;
    std::vector<int> depth;
    std::vector<int> size;
    std::vector<int> heavy;
    std::vector<int> head;
    std::vector<int> position;
    std::vector<int> value;
    Fenwick bit;
    int next = 0;

    void sizes(int u, int p) {
        parent[u] = p;
        size[u] = 1;
        int largest = 0;
        for (int v : g[u]) {
            if (v == p) {
                continue;
            }
            depth[v] = depth[u] + 1;
            sizes(v, u);
            size[u] += size[v];
            if (size[v] > largest) {
                largest = size[v];
                heavy[u] = v;
            }
        }
    }

    void order(int u, int top) {
        head[u] = top;
        position[u] = next;
        ++next;
        if (heavy[u] != -1) {
            order(heavy[u], top);
        }
        for (int v : g[u]) {
            if (v != parent[u] && v != heavy[u]) {
                order(v, v);
            }
        }
    }

public:
    HeavyPaths(const Graph& tree, const std::vector<int>& values)
        : g(tree),
          parent(g.size(), -1),
          depth(g.size(), 0),
          size(g.size(), 0),
          heavy(g.size(), -1),
          head(g.size()),
          position(g.size()),
          value(values),
          bit(g.size()) {
        if (!g.empty()) {
            sizes(0, -1);
            order(0, 0);
            for (std::size_t u = 0; u < g.size(); ++u) {
                bit.add(static_cast<std::size_t>(position[u]), value[u]);
            }
        }
    }

    void set(int u, int x) {
        bit.add(static_cast<std::size_t>(position[u]), x - value[u]);
        value[u] = x;
    }

    long long query(int a, int b) const {
        long long total = 0;
        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]]) {
                std::swap(a, b);
            }
            total += bit.range(static_cast<std::size_t>(position[head[a]]),
                               static_cast<std::size_t>(position[a] + 1));
            a = parent[head[a]];
        }
        if (depth[a] > depth[b]) {
            std::swap(a, b);
        }
        return total
               + bit.range(static_cast<std::size_t>(position[a]),
                           static_cast<std::size_t>(position[b] + 1));
    }
};

int main() {
    auto g = graph(8, {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 6}, {5, 7}});
    std::vector<int> values{1, -2, 3, 4, 5, -6, 7, 8};
    HeavyPaths h(g, values);
    for (int step = 0; step < 10; ++step) {
        int changed = step % 8;
        values[changed] = step - 4;
        h.set(changed, values[changed]);
        for (int source = 0; source < 8; ++source) {
            std::vector<int> parent(8, -1);
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
            for (int target = 0; target < 8; ++target) {
                long long expected = values[source];
                for (int u = target; u != source; u = parent[u]) {
                    expected += values[u];
                }
                assert(h.query(source, target) == expected);
            }
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
