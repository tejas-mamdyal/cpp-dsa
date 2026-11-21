/*
 Triangle with n<=30 rows, row r has r+1 integers; empty returns absence. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

At bottom-up row r, dp[c] becomes minimum sum from triangle cell(r, c) to
the bottom; children are(c) and(c+1) in the next row.

Bottom 4,1,8,3 produces row 7,6,10, then 9,10, then 11.

The route chooses one of exactly two child cells; bottom-up minima solve both
before the parent.

O(number cells) time, O(number rows) auxiliary.

A triangle is not rectangular; row r must contain r+1 entries.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstddef>

std::optional<long long> triangle(const std::vector<std::vector<int>>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    std::vector<long long> dp(a.back().begin(), a.back().end());
    for (int r = static_cast<int>(a.size()) - 2; r >= 0; --r) {
        assert(a[r].size() == static_cast<std::size_t>(r + 1));
        for (int c = 0; c <= r; ++c) {
            dp[c] = a[r][c] + std::min(dp[c], dp[c + 1]);
        }
    }
    return dp[0];
}

int main() {
    assert(triangle({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}) == 11);
    assert(triangle({{-4}}) == -4);
    assert(!triangle({}));
    std::cout << "checks passed\n";
    return 0;
}
