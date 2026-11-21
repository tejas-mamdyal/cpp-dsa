/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

Priority entries store distance snapshots, not permanent vertex
priorities.

0->2->1 costs 2, better than direct 5.

Nonnegative edges ensure the smallest current tentative label cannot be improved
through a farther unsettled vertex.

O((V+E)log(E+2)) time, O(V+E) storage.

Negative edges invalidate finalization; unreachable is not distance 0.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
#include <functional>
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

std::vector<long long> dijkstra(const Weighted& g, int source) {
    std::vector<long long> d(g.size(), INF);
    std::priority_queue<std::pair<long long, int>,
                        std::vector<std::pair<long long, int>>,
                        std::greater<std::pair<long long, int>>>
        q;
    d[source] = 0;
    q.emplace(0, source);
    while (!q.empty()) {
        auto [snapshot, u] = q.top();
        q.pop();
        if (snapshot != d[u]) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            assert(w >= 0);
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
        }
    }
    return d;
}

int main() {
    auto g = weighted(4, {{0, 1, 5}, {0, 2, 1}, {2, 1, 1}});
    auto d = dijkstra(g, 0);
    assert(d[1] == 2 && d[3] == INF);
    std::cout << "checks passed\n";
    return 0;
}
