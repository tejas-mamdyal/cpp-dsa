/*
 At most 10 events, two nonempty half-open integer intervals each; choose one per
event with no pair overlap.

One boolean selects option 0/1 for each event; every overlapping option
pair is forbidden by(not that choice i) or(not that choice j).

Two events each offering[0,2) or[2,4) must choose opposite slots; four
identical-overlap options are impossible.

Each conflict clause rejects exactly one simultaneous pair; all clauses hold
exactly when every selected pair is nonoverlapping.

O(n^2) pair generation plus linear SCC in the generated implication graph.

Half-open touching intervals are compatible; use strict overlap rather than<=.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstdlib>
#include <array>
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

struct Interval {
    int start;
    int end;
};

std::optional<std::vector<int>> choose(const std::vector<std::array<Interval, 2>>& options) {
    std::vector<Clause> clauses;
    for (int i = 0; i < static_cast<int>(options.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(options.size()); ++j) {
            for (int a = 0; a < 2; ++a) {
                for (int b = 0; b < 2; ++b) {
                    auto x = options[i][a];
                    auto y = options[j][b];
                    if (std::max(x.start, y.start) < std::min(x.end, y.end)) {
                        clauses.push_back({a == 1 ? -(i + 1) : i + 1, b == 1 ? -(j + 1) : j + 1});
                    }
                }
            }
        }
    }
    auto value = twoSat(static_cast<int>(options.size()), clauses);
    if (!value) {
        return std::nullopt;
    }
    std::vector<int> out;
    for (bool bit : *value) {
        out.push_back(bit ? 1 : 0);
    }
    return out;
}

int main() {
    std::vector<std::array<Interval, 2>> options{{Interval{0, 2}, Interval{2, 4}},
                                                 {Interval{0, 2}, Interval{2, 4}}};
    auto result = choose(options);
    assert(result && (*result)[0] != (*result)[1]);
    std::vector<std::array<Interval, 2>> impossible{{Interval{0, 2}, Interval{0, 2}},
                                                    {Interval{0, 2}, Interval{0, 2}}};
    assert(!choose(impossible));
    assert(choose({})->empty());
    std::cout << "checks passed\n";
    return 0;
}
