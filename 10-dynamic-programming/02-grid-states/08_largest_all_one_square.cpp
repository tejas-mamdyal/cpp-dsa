/*
 Rectangular binary grid<=30x 30; return side length, not area. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

dp[r][c] is the largest all-one square side ending at the previous input
cell(r-1, c-1); zero padding handles boundaries.

At bottom-right of a 2x 2 all-one grid, three neighbor states 1 permit side 2.

The bottom-right cell is 1 and all three overlapping predecessor squares must
cover a side s-1 square; the minimum limiting side is necessary and sufficient.

O(R*C) time/storage.

Use minimum of all three neighbors, not maximum.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstddef>

std::pair<int, long long> squares(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        return {0, 0};
    }
    std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(a[0].size() + 1, 0));
    int largest = 0;
    long long total = 0;
    for (std::size_t r = 1; r <= a.size(); ++r) {
        for (std::size_t c = 1; c <= a[0].size(); ++c) {
            if (a[r - 1][c - 1]) {
                dp[r][c] = 1 + std::min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]});
                largest = std::max(largest, dp[r][c]);
                total += dp[r][c];
            }
        }
    }
    return {largest, total};
}

int main() {
    assert(squares({{1, 1}, {1, 1}}).first == 2);
    assert(squares({{1, 0}, {1, 1}}).first == 1);
    assert(squares({}).first == 0);
    std::cout << "checks passed\n";
    return 0;
}
