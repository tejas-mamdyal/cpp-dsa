/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

A nonroot u separates a DFS child when low[child]>=discovery[u]; root
separates components only when it has more than one DFS child.

In chain 0-1-2, vertex 1 is a cut; in root-star 0 with two children, root 0 is a
cut.

Without u, the child cannot use a back edge reaching u itself; it must escape
strictly above u. Root has no parent side and needs separate child groups.

O(V+E) time/storage.

Using the bridge strict> condition misses equality cases for vertex removal.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

void findCutVerticesDfs(int node,
                        int parentEdge,
                        const std::vector<std::vector<std::pair<int, int>>>& graph,
                        std::vector<int>& discovery,
                        std::vector<int>& low,
                        std::vector<bool>& cut,
                        int& timer) {
    discovery[node] = timer;
    low[node] = timer;
    ++timer;
    int children = 0;
    for (auto [neighbor, edgeId] : graph[node]) {
        if (edgeId == parentEdge) {
            continue;
        }
        if (discovery[neighbor] != -1) {
            low[node] = std::min(low[node], discovery[neighbor]);
        } else {
            ++children;
            findCutVerticesDfs(neighbor, edgeId, graph, discovery, low, cut, timer);
            low[node] = std::min(low[node], low[neighbor]);
            if (parentEdge != -1 && low[neighbor] >= discovery[node]) {
                cut[node] = true;
            }
        }
    }
    if (parentEdge == -1) {
        cut[node] = children > 1; // A DFS root has its own rule.
    }
}

std::vector<bool> articulation(int n, const std::vector<std::pair<int, int>>& edges) {
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
    std::vector<bool> cut(n);
    int timer = 0;
    for (int node = 0; node < n; ++node) {
        if (discovery[node] == -1) {
            findCutVerticesDfs(node, -1, graph, discovery, low, cut, timer);
        }
    }
    return cut;
}

int main() {
    assert((articulation(3, {{0, 1}, {1, 2}}) == std::vector<bool>{false, true, false}));
    assert((articulation(3, {{0, 1}, {0, 2}}) == std::vector<bool>{true, false, false}));
    assert((articulation(2, {{0, 1}, {0, 1}}) == std::vector<bool>{false, false}));
    std::cout << "checks passed\n";
    return 0;
}
