/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

For each candidate u, the removal components are each child subtree plus
the outside parent-side remainder.

A four-node chain has two central vertices 1 and 2; both leave components of at
most 2.

Those listed pieces exactly partition the tree after removal, so checking their
maximum is necessary and sufficient.

O(V) time, O(V) output/stack.

A centroid balances component sizes; the tree center minimizes maximum distance and
is a different notion.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

int visit(const Graph& g, int u, int parent, std::vector<int>& out) {
    int size = 1;
    int largest = 0;
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        int child = visit(g, v, u, out);
        size += child;
        largest = std::max(largest, child);
    }
    largest = std::max(largest, static_cast<int>(g.size()) - size);
    if (2 * largest <= static_cast<int>(g.size())) {
        out.push_back(u);
    }
    return size;
}

std::vector<int> centroids(const Graph& g) {
    std::vector<int> out;
    if (!g.empty()) {
        visit(g, 0, -1, out);
    }
    std::sort(out.begin(), out.end());
    return out;
}

int main() {
    assert((centroids(graph(4, {{0, 1}, {1, 2}, {2, 3}})) == std::vector<int>{1, 2}));
    assert(centroids(graph(4, {{0, 1}, {0, 2}, {0, 3}})) == std::vector<int>{0});
    std::cout << "checks passed\n";
    return 0;
}
