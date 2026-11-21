/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

A vertex is a cell; four coordinate deltas define legal neighboring
vertices on demand.

Corner 0,0 of a 3x 3 grid has 1,0 and 0,1 only.

The four unit axial moves enumerate exactly orthogonal neighbors, filtered by
bounds.

O(1) query/time and auxiliary storage for four candidates.

Diagonal movement is a different graph; state the movement model.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> neighbors(int rows, int cols, int r, int c) {
    const int dr[4]{1, -1, 0, 0};
    const int dc[4]{0, 0, 1, -1};
    std::vector<std::pair<int, int>> out;
    for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr >= 0 && nc >= 0 && nr < rows && nc < cols) {
            out.emplace_back(nr, nc);
        }
    }
    return out;
}

int main() {
    assert(neighbors(3, 3, 1, 1).size() == 4);
    assert(neighbors(3, 3, 0, 0).size() == 2);
    assert(neighbors(1, 1, 0, 0).empty());
    std::cout << "checks passed\n";
    return 0;
}
