/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Represent an undirected edge as(min endpoint, max endpoint), then
sort/unique.

2-1 and 1-2 both become 1-2, while loop 0-0 stays distinct.

Canonical endpoint order identifies exactly equivalent undirected edges.

O(E log(E+1)) time, O(E) copied input/output.

Do not apply this simplification to a multigraph whose parallel edges matter.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

std::vector<std::pair<int, int>> normalize(std::vector<std::pair<int, int>> edges) {
    for (auto& e : edges) {
        if (e.first > e.second) {
            std::swap(e.first, e.second);
        }
    }
    std::sort(edges.begin(), edges.end());
    edges.erase(std::unique(edges.begin(), edges.end()), edges.end());
    return edges;
}

int main() {
    assert(
        (normalize({{2, 1}, {1, 2}, {0, 0}}) == std::vector<std::pair<int, int>>{{0, 0}, {1, 2}}));
    assert(normalize({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
