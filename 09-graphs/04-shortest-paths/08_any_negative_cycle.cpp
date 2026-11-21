/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Initializing all distances 0 is equivalent to a new source with free arcs
to every vertex.

A negative cycle in disconnected vertices 1,2 becomes reachable from the
conceptual super-source.

The Bellman-Ford extra-pass criterion now applies to every original component.

O(V*E) time, O(V) storage.

This answers cycle existence anywhere, not distances from a specific source.
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

bool anyNegative(int n, const std::vector<Edge>& edges) {
    std::vector<long long> d(static_cast<std::size_t>(n), 0);
    for (int pass = 0; pass < n; ++pass) {
        bool changed = false;
        for (auto e : edges) {
            if (d[e.from] + e.weight < d[e.to]) {
                d[e.to] = d[e.from] + e.weight;
                changed = true;
                if (pass == n - 1) {
                    return true;
                }
            }
        }
        if (!changed) {
            return false;
        }
    }
    return false;
}

int main() {
    assert(anyNegative(3, {{1, 2, -1}, {2, 1, -1}}));
    assert(!anyNegative(3, {{1, 2, -1}}));
    assert(!anyNegative(0, {}));
    std::cout << "checks passed\n";
    return 0;
}
