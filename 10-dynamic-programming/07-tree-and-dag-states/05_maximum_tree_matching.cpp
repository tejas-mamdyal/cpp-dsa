/*
 Valid undirected tree, V<=30; matching edges share no endpoints. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

state 0 leaves u unmatched to children; state 1 is unrestricted optimum.
If u matches child v, use v state 0 so v cannot also match a child.

A star can choose only one center-leaf edge; four-node chain can choose two
disjoint edges.

An optimum either matches no child or exactly one child; all other subtrees
retain unrestricted optima.

O(V) time, O(V) temporary child summaries and recursion.

Adding every beneficial child edge would reuse u more than once.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <array>
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

std::array<int, 2> matching(const Graph& g, int u, int parent) {
    std::vector<std::array<int, 2>> states;
    std::vector<int> children;
    int base = 0;
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        auto child = matching(g, v, u);
        children.push_back(v);
        states.push_back(child);
        base += child[1];
    }
    int best = base;
    for (std::size_t i = 0; i < children.size(); ++i) {
        best = std::max(best, base - states[i][1] + states[i][0] + 1);
    }
    return {base, best};
}

int maximum(const Graph& g) {
    return g.empty() ? 0 : matching(g, 0, -1)[1];
}

int main() {
    assert(maximum(graph(4, {{0, 1}, {0, 2}, {0, 3}})) == 1);
    assert(maximum(graph(4, {{0, 1}, {1, 2}, {2, 3}})) == 2);
    std::cout << "checks passed\n";
    return 0;
}
