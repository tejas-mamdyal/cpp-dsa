/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

First DFS saves exits; second DFS on reversed arcs assigns one component
ID at a time in reverse exit order.

Cycle 0->1->2->0 forms one SCC, while outgoing 3 forms another.

The latest unfinished component is a source in the condensation DAG and cannot
escape to another unassigned component after reversal.

O(V+E) time/storage, up toO(V) recursion.

Ordinary connected components ignore direction and cannot replace mutual-reachability
groups.
*/
#include <iostream>
#include <cassert>
#include <vector>

void finishOrderDfs(int node,
                    const std::vector<std::vector<int>>& graph,
                    std::vector<bool>& seen,
                    std::vector<int>& order) {
    seen[node] = true;
    for (int neighbor : graph[node]) {
        if (!seen[neighbor]) {
            finishOrderDfs(neighbor, graph, seen, order);
        }
    }
    order.push_back(node); // Save exit order, not discovery order.
}

void assignComponentDfs(int node,
                        int id,
                        const std::vector<std::vector<int>>& reversedGraph,
                        std::vector<int>& component) {
    component[node] = id;
    for (int neighbor : reversedGraph[node]) {
        if (component[neighbor] == -1) {
            assignComponentDfs(neighbor, id, reversedGraph, component);
        }
    }
}

std::vector<int> scc(const std::vector<std::vector<int>>& graph) {
    int n = static_cast<int>(graph.size());
    std::vector<std::vector<int>> reversedGraph(n);
    for (int node = 0; node < n; ++node) {
        for (int neighbor : graph[node]) {
            assert(neighbor >= 0 && neighbor < n);
            reversedGraph[neighbor].push_back(node);
        }
    }
    std::vector<bool> seen(n);
    std::vector<int> order;
    for (int node = 0; node < n; ++node) {
        if (!seen[node]) {
            finishOrderDfs(node, graph, seen, order);
        }
    }
    std::vector<int> component(n, -1);
    int id = 0;
    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        if (component[*it] == -1) {
            assignComponentDfs(*it, id, reversedGraph, component);
            ++id;
        }
    }
    return component;
}

int main() {
    auto id = scc({{1}, {2}, {0, 3}, {}});
    assert(id[0] == id[1] && id[1] == id[2] && id[2] != id[3]);
    assert(scc({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
