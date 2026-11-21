/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

A search vertex can mean(original vertex, number-of-steps parity). Encode
both components; one edge flips parity.

State(0, even) moves to(1, odd), and a second move returns(0, even).

Encoding 2*u+p is bijective on vertices times two parities; transitions preserve
the parity meaning.

O(degree) generated transitions, O(V+E) if all product arcs are materialized.

Marking only the original vertex visited would merge states with different future
constraints.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstddef>

using Graph = std::vector<std::vector<int>>;

Graph graph(int n, const std::vector<std::pair<int, int>>& edges, bool directed = false) {
    assert(n >= 0);
    Graph g(static_cast<std::size_t>(n));
    for (auto [u, v] : edges) {
        assert(u >= 0 && v >= 0 && u < n && v < n);
        g[u].push_back(v);
        if (!directed) {
            g[v].push_back(u);
        }
    }
    return g;
}

int encode(int vertex, int parity) {
    assert(vertex >= 0 && parity >= 0 && parity < 2);
    return 2 * vertex + parity;
}

std::pair<int, int> decode(int state) {
    return {state / 2, state % 2};
}

std::vector<int> transitions(const Graph& g, int state) {
    auto [u, parity] = decode(state);
    std::vector<int> out;
    for (int v : g[u]) {
        out.push_back(encode(v, 1 - parity));
    }
    return out;
}

int main() {
    auto g = graph(2, {{0, 1}}, false);
    assert((decode(encode(1, 1)) == std::pair<int, int>{1, 1}));
    assert(transitions(g, encode(0, 0)) == std::vector<int>{encode(1, 1)});
    std::cout << "checks passed\n";
    return 0;
}
