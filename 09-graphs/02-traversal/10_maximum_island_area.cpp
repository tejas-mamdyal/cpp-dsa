/*
 Rectangular binary grid<=30x 30.

Flooding returns 1 plus newly discovered neighboring land counts; maximize
over component roots.

The top-left component contributes 3 and two singletons contribute 1 each, so best
3.

Every land cell contributes once to exactly one flood total.

O(R*C) time/copy/worst-case stack.

Resetting visited between roots would recount the same island.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int eraseLand(std::vector<std::vector<int>>& a, int r, int c) {
    if (r < 0 || c < 0 || r >= static_cast<int>(a.size()) || c >= static_cast<int>(a[0].size())
        || a[r][c] == 0) {
        return 0;
    }
    a[r][c] = 0;
    return 1 + eraseLand(a, r + 1, c) + eraseLand(a, r - 1, c) + eraseLand(a, r, c + 1)
           + eraseLand(a, r, c - 1);
}

int largest(std::vector<std::vector<int>> a) {
    int best = 0;
    for (int r = 0; r < static_cast<int>(a.size()); ++r) {
        for (int c = 0; c < static_cast<int>(a[r].size()); ++c) {
            if (a[r][c]) {
                best = std::max(best, eraseLand(a, r, c));
            }
        }
    }
    return best;
}

int main() {
    assert(largest({{1, 1, 0}, {0, 1, 0}, {1, 0, 1}}) == 3);
    assert(largest({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
