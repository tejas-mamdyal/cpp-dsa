/*
 Rectangular binary grid<=4x 4;0 blocked,1 open; return all nonrevisiting paths from
top-left to bottom-right. Unless narrowed, at most 100 nodes/elements with values in
[-1000,1000]. Recursive examples assume valid acyclic owned structures; exponential searches
use the smaller bounds stated here. No input; keep assertions enabled. Success prints checks
passed.

Coordinates identify cells; four moves describe neighbors. used prevents
cycles on this route and is cleared for siblings.

A 2x 2 open grid yields DR and RD; revisiting the start is prohibited.

Every valid simple path follows one sequence of legal moves; route marking removes
only paths repeating a cell.

Conservative O(V*4^V) time including output, O(V) work; V<=16.

Global permanent visited marking would miss alternate paths to the same cell.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

void walk(const std::vector<std::vector<int>>& grid,
          int r,
          int c,
          std::vector<std::vector<bool>>& used,
          std::string& path,
          std::vector<std::string>& out) {
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0 || used[r][c]) {
        return;
    }
    if (r == rows - 1 && c == cols - 1) {
        out.push_back(path);
        return;
    }
    used[r][c] = true;
    const int dr[4]{1, 0, 0, -1};
    const int dc[4]{0, -1, 1, 0};
    const char move[4]{'D', 'L', 'R', 'U'};
    for (int d = 0; d < 4; ++d) {
        path.push_back(move[d]); // Choose this route element before exploring its completions.
        walk(grid, r + dr[d], c + dc[d], used, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
    used[r][c] = false;
}

std::vector<std::string> maze(const std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return {};
    }
    std::vector<std::vector<bool>> used(grid.size(), std::vector<bool>(grid[0].size(), false));
    std::string path;
    std::vector<std::string> out;
    walk(grid, 0, 0, used, path, out);
    return out;
}

int main() {
    assert((maze({{1, 1}, {1, 1}}) == std::vector<std::string>{"DR", "RD"}));
    assert(maze({{0}}).empty());
    assert((maze({{1}}) == std::vector<std::string>{""}));
    assert(maze({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
