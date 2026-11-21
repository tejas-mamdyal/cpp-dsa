/*
 Square nonnegative capacity matrix, V 2..30, capacities<=1000; source!=sink;
parallel capacities are combined.

Residual[u][v] is additional permitted flow; augmenting subtracts the
bottleneck forward and adds it backward to permit undoing a prior choice.

The four-node network can send total 5 out of source and into sink; after
saturation no residual source-sink path remains.

Capacity/conservation hold after every residual augmentation; absence of any
augmenting route yields a cut whose capacity equals achieved flow.

Dense BFS scans V^2 entries; O(V^3*E) conservative bound, O(V^2) memory. Adjacency-list
Edmonds-Karp has its usual O(V*E^2) bound.

Omitting reverse residual arcs can trap an early poor path choice.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

long long maxFlow(std::vector<std::vector<long long>> residual, int source, int sink) {
    int n = static_cast<int>(residual.size());
    assert(source >= 0 && source < n && sink >= 0 && sink < n && source != sink);
    for (const auto& row : residual) {
        assert(static_cast<int>(row.size()) == n);
        for (auto c : row) {
            assert(c >= 0);
        }
    }
    long long flow = 0;
    for (;;) {
        std::vector<int> parent(n, -1);
        parent[source] = source;
        std::queue<int> q;
        q.push(source);
        while (!q.empty() && parent[sink] == -1) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v) {
                if (parent[v] == -1 && residual[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        if (parent[sink] == -1) {
            return flow;
        }
        long long add = std::numeric_limits<long long>::max();
        for (int v = sink; v != source; v = parent[v]) {
            add = std::min(add, residual[parent[v]][v]);
        }
        for (int v = sink; v != source; v = parent[v]) {
            residual[parent[v]][v] -= add;
            residual[v][parent[v]] += add;
        }
        flow += add;
    }
}

int main() {
    assert(maxFlow({{0, 3, 2, 0}, {0, 0, 1, 2}, {0, 0, 0, 3}, {0, 0, 0, 0}}, 0, 3) == 5);
    assert(maxFlow({{0, 0}, {0, 0}}, 0, 1) == 0);
    std::cout << "checks passed\n";
    return 0;
}
