/*
 Rectangular 0/1 grid<=30x 30; no obstacle cells.

All zero cells are simultaneous BFS sources; distance is minimum number of
four-neighbor steps to any zero.

With zeros at 0,0 and 1,2, their neighboring cells all get distance 1.

FIFO layers from the union of sources discover each cell at its closest source
distance.

O(R*C) time/storage.

No source leaves every distance-1; do not invent distance 0.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <queue>

std::vector<std::vector<int>> nearest(const std::vector<std::vector<int>>& a) {
    if (a.empty()) {
        return {};
    }
    int rows = static_cast<int>(a.size());
    int cols = static_cast<int>(a[0].size());
    std::vector<std::vector<int>> d(a.size(), std::vector<int>(a[0].size(), -1));
    std::queue<std::pair<int, int>> q;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (a[r][c] == 0) {
                d[r][c] = 0;
                q.emplace(r, c);
            }
        }
    }
    const int dr[4]{1, -1, 0, 0};
    const int dc[4]{0, 0, 1, -1};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && d[nr][nc] == -1) {
                d[nr][nc] = d[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
    return d;
}

int main() {
    assert(
        (nearest({{0, 1, 1}, {1, 1, 0}}) == std::vector<std::vector<int>>{{0, 1, 1}, {1, 1, 0}}));
    assert(nearest({{1}})[0][0] == -1);
    std::cout << "checks passed\n";
    return 0;
}
