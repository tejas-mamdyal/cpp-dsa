/*
 Nonnegative capacity matrix, V 2..30; distinct source/sink. Unless a different bound
is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

At termination, the source-reachable residual vertices form one side of
the cut; preserve original capacities separately to compute its value.

All source outgoing capacities total 5 and can be saturated; the returned cut also
has capacity 5.

Every forward cut arc is saturated and every reverse cut flow cancels
appropriately; flow value equals cut capacity, providing matching lower/upper bounds.

Dense Edmonds-Karp bound as in lesson 10, O(V^2) memory.

Sum original directed capacities across the cut, not remaining residual capacities.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <queue>
#include <cstddef>

std::pair<long long, std::vector<bool>>
minimumCut(std::vector<std::vector<long long>> residual, int source, int sink) {
    int n = static_cast<int>(residual.size());
    long long total = 0;
    while (true) {
        std::vector<int> parent(static_cast<std::size_t>(n), -1);
        std::queue<int> q;
        parent[source] = source;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v) {
                if (residual[u][v] > 0 && parent[v] == -1) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        if (parent[sink] == -1) {
            std::vector<bool> reach(static_cast<std::size_t>(n));
            for (int u = 0; u < n; ++u) {
                reach[u] = parent[u] != -1;
            }
            return {total, reach};
        }
        long long add = std::numeric_limits<long long>::max();
        for (int v = sink; v != source; v = parent[v]) {
            add = std::min(add, residual[parent[v]][v]);
        }
        for (int v = sink; v != source; v = parent[v]) {
            residual[parent[v]][v] -= add;
            residual[v][parent[v]] += add;
        }
        total += add;
    }
}

int main() {
    std::vector<std::vector<long long>> a{{0, 3, 2, 0}, {0, 0, 1, 2}, {0, 0, 0, 3}, {0, 0, 0, 0}};
    auto [flow, reach] = minimumCut(a, 0, 3);
    long long cut = 0;
    for (int u = 0; u < 4; ++u) {
        for (int v = 0; v < 4; ++v) {
            if (reach[u] && !reach[v]) {
                cut += a[u][v];
            }
        }
    }
    assert(flow == 5 && cut == flow && reach[0] && !reach[3]);
    std::cout << "checks passed\n";
    return 0;
}
