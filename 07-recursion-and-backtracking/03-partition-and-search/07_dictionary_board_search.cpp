/*
 Board<=4x 4; at most 10 words of length<=10; return distinct present words sorted
lexicographically. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000].
Recursive examples assume valid acyclic owned structures; exponential searches use the smaller
bounds stated here. No input; keep assertions enabled. Success prints checks passed.

The simple baseline searches each word independently and inserts successes
into a set. A trie optimization is introduced after trie fundamentals.

On ab/cd, ab and ac are present, ad is not; duplicate ab appears once in output.

Single-word search is correct for each word; the set enforces the requested
distinct sorted results.

O(W*V*4^L) upper-bound time, O(V+L) work plus saved answers.

Do not introduce trie pointer code before the trie unit merely to optimize this
bounded baseline.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <set>
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

std::vector<std::string> words(const std::vector<std::string>& board,
                               const std::vector<std::string>& dictionary) {
    std::set<std::string> found;
    for (const auto& word : dictionary) {
        if (contains(board, word)) {
            found.insert(word);
        }
    }
    return {found.begin(), found.end()};
}

int main() {
    assert((words({"ab", "cd"}, {"ab", "ac", "ad", "ab"}) == std::vector<std::string>{"ab", "ac"}));
    assert(words({}, {"a"}).empty());
    std::cout << "checks passed\n";
    return 0;
}
