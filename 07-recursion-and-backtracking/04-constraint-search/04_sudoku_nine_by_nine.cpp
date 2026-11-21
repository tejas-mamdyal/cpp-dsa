/*
 9x 9 grid;0 blanks,1..9 clues,3x 3 boxes; reject malformed or conflicting input. Unless
narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume
valid acyclic owned structures; exponential searches use the smaller bounds stated here. No
input; keep assertions enabled. Success prints checks passed.

The 4x 4 algorithm changes box width to 3; rules and choose/undo remain
identical.

The standard first row 5,3,0,0,7,0,0,0,0 ultimately becomes 5,3,4,6,7,8,9,1,2.

Each unfilled cell branches over all values consistent with preserved clues.

O(81*9^E) conservative time, O(E) stack; the bound is exponential despite practical
pruning.

Success retains the solved board intentionally; failure restores every tentative cell.
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
    std::vector<std::vector<int>> a{{5, 3, 0, 0, 7, 0, 0, 0, 0},
                                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                    {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    assert(solve(a, 3));
    assert(valid(a, 3));
    assert((a[0] == std::vector<int>{5, 3, 4, 6, 7, 8, 9, 1, 2}));
    std::cout << "checks passed\n";
    return 0;
}
