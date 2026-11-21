/*
CHECK SQUARE SYMMETRY WITHOUT CONSTRUCTING A TRANSPOSE PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Square matrix; empty is symmetric. IDEA AND STATE: Compare each upper-triangle cell
with its mirrored lower-triangle cell. TRACE: [1,2;2,3] symmetric;[1,4;2,3] not. CORRECTNESS:
Every off-diagonal pair is checked exactly once and diagonal cells match themselves. COST:
O(n^2) worst time,O(1) extra space. PITFALL: Reject non-square shape before indexing mirrored
coordinates. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

bool symmetric(const std::vector<std::vector<int>>& a) {
    for (const auto& row : a) {
        if (row.size() != a.size()) {
            return false;
        }
    }
    for (std::size_t r = 0; r < a.size(); ++r) {
        for (std::size_t c = r + 1; c < a.size(); ++c) {
            if (a[r][c] != a[c][r]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    assert(symmetric({{1, 2}, {2, 3}}));
    assert(!symmetric({{1, 4}, {2, 3}}));
    assert(symmetric({}));
    assert(!symmetric({{1, 2}}));
    std::cout << "checks passed\n";
    return 0;
}
