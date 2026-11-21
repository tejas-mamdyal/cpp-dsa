/*
 At most 8 vertices; undirected symmetric 0/1 matrix; self-loop impossible; k 0..8 labeled
colors. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A vertex is an item, an edge means its two endpoints must differ.
edges[u][v]=1 records that relation. Assign vertices in index order.

A triangle has three pairwise constraints: two colors fail, three colors yield 1,2,3.

When assigning a vertex, check all already assigned neighbors; every completed
coloring then satisfies each edge.

O(n*k^n) time, O(n) colors and recursion beyond the matrix.

This introduces representation locally; later graph traversal algorithms are not
assumed.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <cstddef>

bool paint(const std::vector<std::vector<int>>& edges,
           int vertex,
           int k,
           std::vector<int>& colors) {
    if (vertex == static_cast<int>(edges.size())) {
        return true;
    }
    for (int color = 1; color <= k; ++color) {
        bool ok = true;
        for (int other = 0; other < vertex; ++other) {
            if (edges[vertex][other] && colors[other] == color) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        colors[vertex] = color;
        if (paint(edges, vertex + 1, k, colors)) {
            return true;
        }
        colors[vertex] = 0;
    }
    return false;
}

std::optional<std::vector<int>> coloring(const std::vector<std::vector<int>>& edges, int k) {
    assert(k >= 0);
    for (std::size_t i = 0; i < edges.size(); ++i) {
        assert(edges[i].size() == edges.size());
        if (edges[i][i]) {
            return std::nullopt;
        }
        for (std::size_t j = 0; j < edges.size(); ++j) {
            assert(edges[i][j] == edges[j][i]);
        }
    }
    std::vector<int> colors(edges.size(), 0);
    if (paint(edges, 0, k, colors)) {
        return colors;
    }
    return std::nullopt;
}

int main() {
    std::vector<std::vector<int>> triangle{{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    assert(!coloring(triangle, 2));
    assert(coloring(triangle, 3));
    assert(coloring({}, 0)->empty());
    assert(!coloring({{1}}, 3));
    std::cout << "checks passed\n";
    return 0;
}
