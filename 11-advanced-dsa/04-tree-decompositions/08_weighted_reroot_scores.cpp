/*
 Valid tree<=30 with signed vertex weights; distances count edges, not edge weights.

answer[u]=sum weight[v]*distance(u, v); sub[u] sums original-root subtree
weights.

For chain weights 2,1,3, root 0 score 1+6=7; moving to 1 changes by total 6-2*sub
1(4)=-2, score 5.

Each vertex contribution changes by its signed weight times+1 or-1 across the
reroot edge.

O(V) time/storage.

Signed weights are algebraically allowed, but minimum-distance interpretations may no
longer mean a physical nonnegative cost.
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

void build(const Graph& g,
           const std::vector<int>& weight,
           int u,
           int parent,
           std::vector<long long>& sub,
           std::vector<long long>& answer) {
    sub[u] = weight[u];
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        build(g, weight, v, u, sub, answer);
        sub[u] += sub[v];
        answer[u] += answer[v] + sub[v];
    }
}

void reroot(const Graph& g,
            int u,
            int parent,
            long long total,
            const std::vector<long long>& sub,
            std::vector<long long>& answer) {
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        answer[v] = answer[u] + total - 2 * sub[v];
        reroot(g, v, u, total, sub, answer);
    }
}

std::vector<long long> weightedSums(const Graph& g, const std::vector<int>& weight) {
    std::vector<long long> sub(g.size(), 0);
    std::vector<long long> answer(g.size(), 0);
    if (!g.empty()) {
        build(g, weight, 0, -1, sub, answer);
        reroot(g, 0, -1, sub[0], sub, answer);
    }
    return answer;
}

int main() {
    assert(
        (weightedSums(graph(3, {{0, 1}, {1, 2}}), {2, 1, 3}) == std::vector<long long>{7, 5, 5}));
    std::cout << "checks passed\n";
    return 0;
}
