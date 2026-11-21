/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Edge has named from, to, weight fields; adjacency pairs mean destination,
weight.

Arc 0->2 of weight-2 stores(2,-2) in row 0; it is not distance 2 or an undirected
edge.

Each adjacency item retains its originating edge endpoint and cost.

O(V+E) construction/storage.

Negative weights are representable here; some later algorithms explicitly forbid
them.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <limits>
#include <cstddef>

struct Edge {
    int from;
    int to;
    int weight;
};

using Weighted = std::vector<std::vector<std::pair<int, int>>>;
constexpr long long INF = std::numeric_limits<long long>::max() / 4;

Weighted weighted(int n, const std::vector<Edge>& edges, bool directed = true) {
    Weighted g(static_cast<std::size_t>(n));
    for (auto e : edges) {
        g[e.from].emplace_back(e.to, e.weight);
        if (!directed) {
            g[e.to].emplace_back(e.from, e.weight);
        }
    }
    return g;
}

int main() {
    auto g = weighted(3, {{0, 1, 7}, {0, 2, -2}}, true);
    assert((g[0] == std::vector<std::pair<int, int>>{{1, 7}, {2, -2}}));
    assert(g[1].empty());
    std::cout << "checks passed\n";
    return 0;
}
