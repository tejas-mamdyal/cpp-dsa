/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Row u, column v records edge existence, not reachability through other
vertices.

Insert 0->1 twice; one true entry remains, and 1->0 is false in directed mode.

Each assignment marks exactly a listed edge and its reverse only when undirected.

O(V^2+E) construction, O(1) edge lookup, O(V^2) storage.

A boolean matrix discards parallel-edge multiplicity.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstddef>

std::vector<std::vector<bool>>
matrix(int n, const std::vector<std::pair<int, int>>& edges, bool directed) {
    std::vector<std::vector<bool>> a(static_cast<std::size_t>(n),
                                     std::vector<bool>(static_cast<std::size_t>(n), false));
    for (auto [u, v] : edges) {
        a[u][v] = true;
        if (!directed) {
            a[v][u] = true;
        }
    }
    return a;
}

int main() {
    auto a = matrix(3, {{0, 1}, {0, 1}}, false);
    assert(a[0][1] && a[1][0] && !a[0][2]);
    auto d = matrix(2, {{0, 1}}, true);
    assert(d[0][1] && !d[1][0]);
    assert(matrix(0, {}, true).empty());
    std::cout << "checks passed\n";
    return 0;
}
