/*
 Nonempty rectangular integer grid<=30x 30; start coordinates valid. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

Replacement color doubles as visited marking only when it differs from the
original color.

Starting 0,0 replaces the three connected 1 cells but not the disconnected 1 at
1,2.

Exactly original-color cells connected to the start satisfy the recursive
acceptance condition.

O(R*C) time, worst-case O(R*C) recursion.

If old==new, return first or recursive revisits never become blocked.
*/
#include <iostream>
#include <cassert>
#include <vector>

void fill(std::vector<std::vector<int>>& a, int r, int c, int old, int color) {
    if (r < 0 || c < 0 || r >= static_cast<int>(a.size()) || c >= static_cast<int>(a[0].size())
        || a[r][c] != old) {
        return;
    }
    a[r][c] = color;
    fill(a, r + 1, c, old, color);
    fill(a, r - 1, c, old, color);
    fill(a, r, c + 1, old, color);
    fill(a, r, c - 1, old, color);
}

void paint(std::vector<std::vector<int>>& a, int r, int c, int color) {
    int old = a[r][c];
    if (old == color) {
        return;
    }
    fill(a, r, c, old, color);
}

int main() {
    std::vector<std::vector<int>> a{{1, 1, 0}, {1, 0, 1}};
    paint(a, 0, 0, 2);
    assert((a == std::vector<std::vector<int>>{{2, 2, 0}, {2, 0, 1}}));
    paint(a, 0, 0, 2);
    std::cout << "checks passed\n";
    return 0;
}
