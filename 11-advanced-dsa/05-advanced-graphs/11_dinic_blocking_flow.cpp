/*
 Directed capacities 0..1000, V 2..30; loops/parallel arcs allowed; call flow on a
freshly built network with distinct source/sink.

BFS levels keep only forward one-level residual arcs; next[u] remembers
exhausted edge candidates during one blocking-flow phase.

The network sends its shortest-layer routes until blocked, then a fresh BFS may
expose a longer rerouting opportunity.

Each phase blocks every shortest residual route; when the sink becomes
unreachable, no augmentation exists and the flow is optimal.

O(V^2*E) general bound, O(V+E) storage; unit/bipartite networks admit stronger
specialized bounds.

Reset current-edge pointers for each new level graph, but not for every recursive
send.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <cstddef>

class Dinic {
    struct Edge {
        int to;
        long long capacity;
    };

    std::vector<Edge> edges;
    std::vector<std::vector<int>> outgoing;
    std::vector<int> level;
    std::vector<std::size_t> next;

    bool layers(int source, int sink) {
        std::fill(level.begin(), level.end(), -1);
        std::queue<int> q;
        level[source] = 0;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : outgoing[u]) {
                const auto& e = edges[id];
                if (e.capacity > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] != -1;
    }

    long long send(int u, int sink, long long limit) {
        if (u == sink) {
            return limit;
        }
        for (auto& index = next[u]; index < outgoing[u].size(); ++index) {
            int id = outgoing[u][index];
            int v = edges[id].to;
            if (edges[id].capacity == 0 || level[v] != level[u] + 1) {
                continue;
            }
            long long pushed = send(v, sink, std::min(limit, edges[id].capacity));
            if (pushed > 0) {
                edges[id].capacity -= pushed;
                edges[id ^ 1].capacity += pushed;
                return pushed;
            }
        }
        return 0;
    }

public:
    explicit Dinic(int n)
        : outgoing(static_cast<std::size_t>(n)),
          level(static_cast<std::size_t>(n)),
          next(static_cast<std::size_t>(n)) {
    }

    void add(int u, int v, long long capacity) {
        assert(capacity >= 0);
        int id = static_cast<int>(edges.size());
        edges.push_back({v, capacity});
        edges.push_back({u, 0});
        outgoing[u].push_back(id);
        outgoing[v].push_back(id + 1);
    }

    long long flow(int source, int sink) {
        assert(source != sink);
        long long total = 0;
        while (layers(source, sink)) {
            std::fill(next.begin(), next.end(), 0);
            while (true) {
                long long pushed = send(source, sink, std::numeric_limits<long long>::max() / 4);
                if (pushed == 0) {
                    break;
                }
                total += pushed;
            }
        }
        return total;
    }
};

int main() {
    Dinic d(4);
    d.add(0, 1, 3);
    d.add(0, 2, 2);
    d.add(1, 2, 1);
    d.add(1, 3, 2);
    d.add(2, 3, 3);
    d.add(0, 0, 99);
    assert(d.flow(0, 3) == 5);
    Dinic disconnected(3);
    disconnected.add(0, 1, 7);
    assert(disconnected.flow(0, 2) == 0);
    Dinic parallel(2);
    parallel.add(0, 1, 2);
    parallel.add(0, 1, 3);
    assert(parallel.flow(0, 1) == 5);
    std::cout << "checks passed\n";
    return 0;
}
