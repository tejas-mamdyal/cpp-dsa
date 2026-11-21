/*
 4x 4 grid;0 blank,1..4 values,2x 2 boxes; reject invalid clues and preserve input on
failure. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Find first blank and try all legal values. A failed branch resets its own
cell. Validate clues before searching.

In row 1,0,0,4, the missing values 2 and 3 must also satisfy their columns and 2x 2
boxes.

A completed valid board satisfies every constraint; trying every legal value
cannot omit a solution.

O(n^2* n^E) conservative time, E blanks, n 4; O(E) frames.

A filled but invalid board is not solved; validate existing clues first.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

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
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (a[r][c] != 0) {
                continue;
            }
            for (int value = 1; value <= n; ++value) {
                if (!allowed(a, r, c, value, box)) {
                    continue;
                }
                a[r][c] = value;
                if (search(a, box)) {
                    return true;
                }
                a[r][c] = 0;
            }
            return false;
        }
    }
    return true;
}

bool solve(std::vector<std::vector<int>>& a, int box) {
    assert(box == 2 || box == 3);
    if (!valid(a, box)) {
        return false;
    }
    return search(a, box);
}

int main() {
    std::vector<std::vector<int>> a{{1, 0, 0, 4}, {0, 4, 1, 0}, {0, 1, 4, 0}, {4, 0, 0, 1}};
    assert(solve(a, 2));
    assert(valid(a, 2));
    for (const auto& row : a) {
        assert(std::find(row.begin(), row.end(), 0) == row.end());
    }
    a[0][0] = a[0][1];
    auto bad = a;
    assert(!solve(a, 2) && a == bad);
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
