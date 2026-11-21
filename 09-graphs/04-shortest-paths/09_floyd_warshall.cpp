/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Before processing k, d[i][j] permits only earlier internal vertices;
either keep the old route or split via k.

Parallel 0->1 weights 5 and 3 retain 3; via 1 extends to 2 with total 2.

Any route either excludes k or uniquely splits at k into two routes using earlier
allowed internal vertices.

O(V^3) time, O(V^2) storage.

Keep k outermost; guard INF before adding. Negative-cycle-affected pairs need
separate handling.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

std::vector<std::vector<long long>> allPairs(int n, const std::vector<Edge>& edges) {
    std::vector<std::vector<long long>> d(static_cast<std::size_t>(n),
                                          std::vector<long long>(static_cast<std::size_t>(n), INF));
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
    }
    for (auto e : edges) {
        d[e.from][e.to] = std::min(d[e.from][e.to], 1LL * e.weight);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = std::min(
                        d[i][j],
                        std::max(
                            -INF,
                            d[i][k]
                                + d[k]
                                   [j])); // Saturate negative-cycle growth before it can overflow.
                }
            }
        }
    }
    return d;
}

int main() {
    auto d = allPairs(4, {{0, 1, 5}, {0, 1, 3}, {1, 2, -1}});
    assert(d[0][2] == 2 && d[2][0] == INF && d[3][3] == 0);
    std::vector<Edge> dense;
    for (int u = 0; u < 30; ++u) {
        for (int v = 0; v < 30; ++v) {
            dense.push_back({u, v, -1000000});
        }
    }
    auto negative = allPairs(30, dense);
    assert(negative[0][0] < 0 && negative[0][0] >= -INF);
    std::cout << "checks passed\n";
    return 0;
}
