/*
 Rectangular binary grid, at most 30 rows/columns; four-direction moves. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

The grid is copied so marking land 0 does not mutate caller data; each
unmarked land root starts one component.

Three connected top-left cells form one island; two separated bottom cells add two
more.

Flooding consumes exactly the orthogonally connected land component once.

O(R*C) time, O(R*C) copied grid and worst-case recursion.

Diagonal contact is not connectivity in this model.
*/
#include <iostream>
#include <cassert>
#include <vector>

int eraseLand(std::vector<std::vector<int>>& a, int r, int c) {
    if (r < 0 || c < 0 || r >= static_cast<int>(a.size()) || c >= static_cast<int>(a[0].size())
        || a[r][c] == 0) {
        return 0;
    }
    a[r][c] = 0;
    return 1 + eraseLand(a, r + 1, c) + eraseLand(a, r - 1, c) + eraseLand(a, r, c + 1)
           + eraseLand(a, r, c - 1);
}

int islands(std::vector<std::vector<int>> a) {
    int count = 0;
    for (int r = 0; r < static_cast<int>(a.size()); ++r) {
        for (int col = 0; col < static_cast<int>(a[r].size()); ++col) {
            if (a[r][col]) {
                eraseLand(a, r, col);
                ++count;
            }
        }
    }
    return count;
}

int main() {
    assert(islands({{1, 1, 0}, {0, 1, 0}, {1, 0, 1}}) == 3);
    assert(islands({}) == 0);
    assert(islands({{0}}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
