/*
 Valid 4x 4 or 9x 9 Sudoku domains as in 03/04. Unless narrowed, at most 100
nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

Minimum remaining values (MRV) means choose a blank with the fewest
currently legal values. A zero-option cell rejects the branch.

If one blank permits only 2 and another permits 1,2,3, fill the forced 2 first; no
valid value is discarded.

Reordering independent blank choices preserves all complete assignments; only
illegal values are removed.

O(n^3* n^E) conservative time, O(E*n) active option storage; heuristic does not remove
exponential worst case.

A heuristic changes order; it is not a proof of polynomial runtime.
*/
#include <iostream>
#include <cassert>
#include <vector>

bool allowed(const std::vector<std::vector<int>>& a, int r, int c, int value, int box) {
    int n = box * box;
    for (int i = 0; i < n; ++i) {
        if (a[r][i] == value || a[i][c] == value) {
            return false;
        }
    }
    int top = r / box * box;
    int left = c / box * box;
    for (int i = top; i < top + box; ++i) {
        for (int j = left; j < left + box; ++j) {
            if (a[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

bool valid(std::vector<std::vector<int>>& a, int box) {
    int n = box * box;
    if (static_cast<int>(a.size()) != n) {
        return false;
    }
    for (const auto& row : a) {
        if (static_cast<int>(row.size()) != n) {
            return false;
        }
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            int value = a[r][c];
            if (value < 0 || value > n) {
                return false;
            }
            if (value == 0) {
                continue;
            }
            a[r][c] = 0;
            bool ok = allowed(a, r, c, value, box);
            a[r][c] = value;
            if (!ok) {
                return false;
            }
        }
    }
    return true;
}

bool search(std::vector<std::vector<int>>& a, int box) {
    int n = box * box;
    int chosenR = -1;
    int chosenC = -1;
    std::vector<int> best;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (a[r][c] != 0) {
                continue;
            }
            std::vector<int> options;
            for (int x = 1; x <= n; ++x) {
                if (allowed(a, r, c, x, box)) {
                    options.push_back(x);
                }
            }
            if (options.empty()) {
                return false;
            }
            if (chosenR == -1 || options.size() < best.size()) {
                chosenR = r;
                chosenC = c;
                best = options;
            }
        }
    }
    if (chosenR == -1) {
        return true;
    }
    for (int x : best) {
        a[chosenR][chosenC] = x;
        if (search(a, box)) {
            return true;
        }
        a[chosenR][chosenC] = 0;
    }
    return false;
}

bool solve(std::vector<std::vector<int>>& a, int box) {
    return valid(a, box) && search(a, box);
}

int main() {
    std::vector<std::vector<int>> a{{1, 0, 0, 4}, {0, 4, 1, 0}, {0, 1, 4, 0}, {4, 0, 0, 1}};
    assert(solve(a, 2));
    assert(valid(a, 2));
    // Valid clues can still be impossible;failure must preserve every clue and blank.
    std::vector<std::vector<int>> impossible{
        {0, 1, 2, 3}, {4, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    auto original = impossible;
    assert(valid(impossible, 2));
    assert(!solve(impossible, 2));
    assert(impossible == original);
    std::cout << "checks passed\n";
    return 0;
}
