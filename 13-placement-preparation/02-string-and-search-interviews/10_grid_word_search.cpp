/*
 Rectangular grid<=4x 4; word length<=8; four-neighbor moves. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

used belongs to the current route and is restored after trying its
continuations.

ABCB would reuse the B cell and is rejected.

Every legal route branches to all adjacent unused matching cells; restoration
keeps siblings independent.

O(rows*cols*4^L) conservative time, O(rows*cols+L) work.

Global permanent visitation would prune valid routes from other starts.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

bool visit(const std::vector<std::string>& board,
           const std::string& word,
           int r,
           int col,
           std::size_t index,
           std::vector<std::vector<bool>>& used) {
    if (index == word.size()) {
        return true;
    }
    if (r < 0 || col < 0 || r >= static_cast<int>(board.size())
        || col >= static_cast<int>(board[0].size()) || used[r][col]
        || board[r][col] != word[index]) {
        return false;
    }
    used[r][col] = true;
    bool found = visit(board, word, r + 1, col, index + 1, used)
                 || visit(board, word, r - 1, col, index + 1, used)
                 || visit(board, word, r, col + 1, index + 1, used)
                 || visit(board, word, r, col - 1, index + 1, used);
    used[r][col] = false;
    return found;
}

bool exists(const std::vector<std::string>& board, const std::string& word) {
    if (word.empty()) {
        return true;
    }
    if (board.empty() || board[0].empty()) {
        return false;
    }
    std::vector<std::vector<bool>> used(board.size(), std::vector<bool>(board[0].size()));
    for (int r = 0; r < static_cast<int>(board.size()); ++r) {
        for (int col = 0; col < static_cast<int>(board[0].size()); ++col) {
            if (visit(board, word, r, col, 0, used)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    assert(exists({"ABCE", "SFCS", "ADEE"}, "ABCCED"));
    assert(!exists({"ABCE", "SFCS", "ADEE"}, "ABCB"));
    assert(exists({}, ""));
    std::cout << "checks passed\n";
    return 0;
}
