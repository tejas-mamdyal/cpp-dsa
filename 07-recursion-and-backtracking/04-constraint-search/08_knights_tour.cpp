/*
 n 1..5 square board, start 0,0; return a first route visiting every cell once or
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A knight moves by one and two coordinates in either order. Board cells
store step numbers or -1 for unused.

n 1 immediately saves step 0; n 3 exhausts legal branches without a complete tour.

All legal unused destinations are explored; step count n*n proves every cell was
visited exactly once.

O(8^(n*n)) upper-bound time, O(n*n) board/stack.

This bounded baseline has no efficient-runtime promise for larger boards.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <cstddef>

bool tour(std::vector<std::vector<int>>& board, int r, int c, int step) {
    int n = static_cast<int>(board.size());
    board[r][c] = step;
    if (step == n * n - 1) {
        return true;
    }
    const int dr[8]{2, 1, -1, -2, -2, -1, 1, 2};
    const int dc[8]{1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nc >= 0 && nr < n && nc < n && board[nr][nc] == -1
            && tour(board, nr, nc, step + 1)) {
            return true;
        }
    }
    board[r][c] = -1;
    return false;
}

std::optional<std::vector<std::vector<int>>> knight(int n) {
    assert(n >= 1 && n <= 5);
    std::vector<std::vector<int>> board(static_cast<std::size_t>(n),
                                        std::vector<int>(static_cast<std::size_t>(n), -1));
    if (tour(board, 0, 0, 0)) {
        return board;
    }
    return std::nullopt;
}

int main() {
    assert((knight(1) == std::optional<std::vector<std::vector<int>>>{{{0}}}));
    assert(!knight(3));
    std::cout << "checks passed\n";
    return 0;
}
