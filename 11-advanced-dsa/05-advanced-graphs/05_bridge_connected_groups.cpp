/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Delete bridge IDs conceptually, then use DSU on every remaining edge to
identify 2-edge-connected groups.

A triangle remains one group after its tail bridge is removed; the tail vertex
becomes another.

Bridges are exactly edges whose removal separates connectivity; within a
bridge-free component every edge has an alternate route.

O(V+E*alpha(V)) after linear bridge discovery, O(V+E) storage.

Vertex-biconnected blocks are different and may share articulation vertices.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstddef>
#include <numeric>

void findBridgesDfs(int node,
                    int parentEdge,
                    const std::vector<std::vector<std::pair<int, int>>>& graph,
                    std::vector<int>& discovery,
                    std::vector<int>& low,
                    int& timer,
                    std::vector<int>& answer) {
    discovery[node] = timer;
    low[node] = timer;
    ++timer;
    for (auto [neighbor, edgeId] : graph[node]) {
        if (edgeId == parentEdge) {
            continue;
        }
        if (discovery[neighbor] != -1) {
            low[node] = std::min(low[node], discovery[neighbor]);
        } else {
            findBridgesDfs(neighbor, edgeId, graph, discovery, low, timer, answer);
            low[node] = std::min(low[node], low[neighbor]);
            if (low[neighbor] > discovery[node]) {
                answer.push_back(edgeId);
            }
        }
    }
}

std::vector<int> bridges(int n, const std::vector<std::pair<int, int>>& edges) {
    assert(n >= 0);
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int id = 0; id < static_cast<int>(edges.size()); ++id) {
        auto [from, to] = edges[id];
        assert(from >= 0 && from < n && to >= 0 && to < n);
        graph[from].push_back({to, id});
        graph[to].push_back({from, id});
    }
    std::vector<int> discovery(n, -1);
    std::vector<int> low(n);
    std::vector<int> answer;
    int timer = 0;
    for (int node = 0; node < n; ++node) {
        if (discovery[node] == -1) {
            findBridgesDfs(node, -1, graph, discovery, low, timer, answer);
        }
    }
    return answer;
}

class DSU {
    std::vector<int> parent;
    std::vector<int> size;

public:
    explicit DSU(int n)
        : parent(static_cast<std::size_t>(n)),
          size(static_cast<std::size_t>(n), 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (size[a] < size[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int count(int u) {
        return size[find(u)];
    }
};

std::vector<int> groups(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<bool> cut(edges.size(), false);
    for (int id : bridges(n, edges)) {
        cut[id] = true;
    }
    DSU dsu(n);
    for (std::size_t i = 0; i < edges.size(); ++i) {
        if (!cut[i]) {
            dsu.unite(edges[i].first, edges[i].second);
        }
    }
    std::vector<int> id(static_cast<std::size_t>(n));
    for (int u = 0; u < n; ++u) {
        id[u] = dsu.find(u);
    }
    return id;
}

int main() {
    auto id = groups(4, {{0, 1}, {1, 2}, {2, 0}, {2, 3}});
    assert(id[0] == id[2] && id[2] != id[3]);
    std::cout << "checks passed\n";
    return 0;
}
