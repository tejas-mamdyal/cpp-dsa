/*
 At most 30 boolean variables; nonzero signed literals within variable count;
two-literal CNF clauses, including repeated literals.

Literal positive v means variable v-1 true, negative means false; encode
false/true as 2v,2v+1. Clause(a or b) creates not-a->b and not-b->a.

Clauses x and not-x as repeated-literal pairs put both truth literals in one SCC
and are impossible.

Mutual implication of a literal and its negation is contradictory; otherwise
assigning the later source-to-sink SCC literal true respects all implications.

O(variables+clauses) time/storage via SCC.

Component-order direction depends on the SCC implementation; validate the produced
assignment against every clause.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <cstdlib>
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

struct Clause {
    int first;
    int second;
};

std::optional<std::vector<bool>> twoSat(int variables, const std::vector<Clause>& clauses) {
    std::vector<std::vector<int>> g(static_cast<std::size_t>(2 * variables));
    auto index = [variables](int literal) {
        int variable = std::abs(literal) - 1;
        assert(variable >= 0 && variable < variables);
        return 2 * variable + (literal > 0 ? 1 : 0);
    };
    for (auto clause : clauses) {
        int a = index(clause.first);
        int b = index(clause.second);
        g[a ^ 1].push_back(b);
        g[b ^ 1].push_back(a);
    }
    auto component = scc(g);
    std::vector<bool> value(static_cast<std::size_t>(variables));
    for (int v = 0; v < variables; ++v) {
        if (component[2 * v] == component[2 * v + 1]) {
            return std::nullopt;
        }
        value[v] = component[2 * v + 1] > component[2 * v];
    }
    return value;
}

int main() {
    auto solution = twoSat(2, {{1, 2}, {-1, 2}, {1, -2}});
    assert(solution && (*solution)[0] && (*solution)[1]);
    assert(!twoSat(1, {{1, 1}, {-1, -1}}));
    assert(twoSat(0, {})->empty());
    std::cout << "checks passed\n";
    return 0;
}
