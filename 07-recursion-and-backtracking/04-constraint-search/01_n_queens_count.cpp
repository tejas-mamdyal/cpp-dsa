/*
 n 0..10; count nonattacking one-queen-per-row boards; zero has one empty arrangement.
Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples
assume valid acyclic owned structures; exponential searches use the smaller bounds stated
here. No input; keep assertions enabled. Success prints checks passed.

row is the next unfilled row; column, row-column+n-1, and row+column identify
conflicts. This expands the inherited counting algorithm.

At n 4, the route columns 1,3,0,2 survives; trying column 1 again in the next row is
immediately rejected.

Earlier rows remain mutually legal; each legal next column extends exactly one
board, with all marks undone afterward.

O(n*n!) upper-bound time, O(n) work and no saved boards.

Avoid chained assignments so every marked and restored constraint is visible.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

int main() {
    assert(queens(0) == 1);
    assert(queens(1) == 1);
    assert(queens(2) == 0);
    assert(queens(3) == 0);
    assert(queens(4) == 2);
    assert(queens(8) == 92);
    std::cout << "checks passed\n";
    return 0;
}
