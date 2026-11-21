/*
 Rectangular character board<=4x 4; word length<=16; empty word is present even on an
empty board. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000].
Recursive examples assume valid acyclic owned structures; exponential searches use the smaller
bounds stated here. No input; keep assertions enabled. Success prints checks passed.

i is the next required character; each matched cell is temporarily
reserved. Baseline enumerates all simple paths.

ABCE/SFCS/ADEE contains ABCCED but not ABCB because the second B would reuse a
cell.

Character checks and route marking accept exactly legal adjacent spellings; undo
runs before success returns.

O(V*4^L) upper-bound time, O(V+L) auxiliary space.

Short-circuit success must still clear the current cell.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

bool find(const std::vector<std::string>& board,
          const std::string& word,
          int r,
          int c,
          std::size_t i,
          std::vector<std::vector<bool>>& used) {
    if (i == word.size()) {
        return true;
    }
    int rows = static_cast<int>(board.size());
    int cols = rows == 0 ? 0 : static_cast<int>(board[0].size());
    if (r < 0 || c < 0 || r >= rows || c >= cols || used[r][c] || board[r][c] != word[i]) {
        return false;
    }
    used[r][c] = true;
    bool found =
        find(board, word, r + 1, c, i + 1, used) || find(board, word, r - 1, c, i + 1, used)
        || find(board, word, r, c + 1, i + 1, used) || find(board, word, r, c - 1, i + 1, used);
    used[r][c] = false;
    return found;
}

bool contains(const std::vector<std::string>& board, const std::string& word) {
    if (word.empty()) {
        return true;
    }
    if (board.empty()) {
        return false;
    }
    std::vector<std::vector<bool>> used(board.size(), std::vector<bool>(board[0].size(), false));
    for (int r = 0; r < static_cast<int>(board.size()); ++r) {
        for (int c = 0; c < static_cast<int>(board[0].size()); ++c) {
            if (find(board, word, r, c, 0, used)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    assert(contains({"ABCE", "SFCS", "ADEE"}, "ABCCED"));
    assert(!contains({"ABCE", "SFCS", "ADEE"}, "ABCB"));
    assert(contains({}, ""));
    assert(!contains({}, "a"));
    std::cout << "checks passed\n";
    return 0;
}
