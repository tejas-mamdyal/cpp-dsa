/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

discovery records DFS entry times; low[u] is the earliest discovery
reachable from subtree u through tree edges plus one back edge.

Triangle 0,1,2 has alternate routes, but edge 2-3 is the only connection to 3.

low[child]>discovery[parent] means no other edge reconnects that child subtree to
the parent side.

O(V+E) time/storage.

Skip the parent edge ID, not every edge to the parent vertex.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

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

int main() {
    auto out = bridges(4, {{0, 1}, {1, 2}, {2, 0}, {2, 3}});
    assert(out == std::vector<int>{3});
    assert(bridges(2, {{0, 1}, {0, 1}}).empty());
    assert(bridges(0, {}).empty());
    std::cout << "checks passed\n";
    return 0;
}
