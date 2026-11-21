/*
 n 0..7; compare N-queen counts to independent next_permutation enumeration. Unless
narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume
valid acyclic owned structures; exponential searches use the smaller bounds stated here. No
input; keep assertions enabled. Success prints checks passed.

A complete permutation already uses each column once; test every row pair
for diagonal conflicts.

At n 4,24 column permutations reduce to two diagonal-safe boards.

Every legal board is a column permutation; pairwise checks characterize all
diagonal constraints independently of the marked-array solver.

Oracle O(n^2*n!) time, O(n) auxiliary; limited to tiny n.

Count equality is appropriate here because both algorithms count the same fully
defined board objects.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstddef>

int place(
    int row, int n, std::vector<bool>& columns, std::vector<bool>& down, std::vector<bool>& up) {
    if (row == n) {
        return 1;
    }
    int total = 0;
    for (int c = 0; c < n; ++c) {
        int d = row - c + n - 1;
        int u = row + c;
        if (columns[c] || down[d] || up[u]) {
            continue;
        }
        columns[c] = true; // Mark the chosen column as unavailable.
        down[d] = true;    // Mark the descending diagonal identity.
        up[u] = true;      // Mark the ascending diagonal identity.
        total += place(row + 1, n, columns, down, up);
        columns[c] = false; // Undo the column reservation.
        down[d] = false;    // Undo the descending diagonal reservation.
        up[u] = false;      // Undo the ascending diagonal reservation.
    }
    return total;
}

int queens(int n) {
    assert(n >= 0 && n <= 10);
    if (n == 0) {
        return 1;
    }
    std::vector<bool> columns(static_cast<std::size_t>(n));
    std::vector<bool> down(static_cast<std::size_t>(2 * n - 1));
    std::vector<bool> up(static_cast<std::size_t>(2 * n - 1));
    return place(0, n, columns, down, up);
}

int oracle(int n) {
    std::vector<int> columns;
    for (int i = 0; i < n; ++i) {
        columns.push_back(i);
    }
    int count = 0;
    do {
        bool ok = true;
        for (int r = 0; r < n; ++r) {
            for (int s = r + 1; s < n; ++s) {
                if (std::abs(columns[r] - columns[s]) == s - r) {
                    ok = false;
                }
            }
        }
        if (ok) {
            ++count;
        }
    } while (std::next_permutation(columns.begin(), columns.end()));
    return count;
}

int main() {
    for (int n = 0; n <= 7; ++n) {
        assert(queens(n) == oracle(n));
    }
    std::cout << "checks passed\n";
    return 0;
}
