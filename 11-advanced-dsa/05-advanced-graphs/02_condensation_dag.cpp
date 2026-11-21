/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Each SCC becomes one vertex; only arcs between different IDs remain, and
duplicates are removed.

0<->1 followed by two arcs 1->2 becomes a two-vertex DAG with one arc.

A directed cycle among contracted components would imply mutual reachability and
merge those components, contradicting maximality.

O(V+E log(E+1)) time with set deduplication, O(V+E) storage.

Internal self-arcs must be removed before treating the condensation as a DAG.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cstddef>

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

std::vector<std::vector<int>> condensation(const std::vector<std::vector<int>>& g) {
    auto id = scc(g);
    if (id.empty()) {
        return {};
    }
    int count = 1 + *std::max_element(id.begin(), id.end());
    std::vector<std::vector<int>> out(static_cast<std::size_t>(count));
    std::set<std::pair<int, int>> edges;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        for (int v : g[u]) {
            if (id[u] != id[v]) {
                edges.emplace(id[u], id[v]);
            }
        }
    }
    for (auto [u, v] : edges) {
        out[u].push_back(v);
    }
    return out;
}

int main() {
    auto g = condensation({{1}, {0, 2, 2}, {}});
    assert(g.size() == 2);
    int arcs = 0;
    for (const auto& row : g) {
        arcs += static_cast<int>(row.size());
    }
    assert(arcs == 1);
    std::cout << "checks passed\n";
    return 0;
}
