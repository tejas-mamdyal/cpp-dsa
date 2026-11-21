/*
 Rectangular signed grid<=30x 30; empty has no route. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

dp[r][c] is minimum sum including both endpoints of a down/right route to
this cell.

The classic 3x 3 optimum 1+3+1+1+1=7 follows the top and right edge.

Every route enters from above or left, so the cheaper legal predecessor plus
current value is optimal.

O(R*C) time/storage.

Negative cell values are allowed because movement is acyclic; do not use a
nonnegative-window argument.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <limits>
#include <cstddef>

std::optional<long long> minimum(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        return std::nullopt;
    }
    const long long inf = std::numeric_limits<long long>::max() / 4;
    std::vector<std::vector<long long>> dp(a.size(), std::vector<long long>(a[0].size(), inf));
    for (std::size_t r = 0; r < a.size(); ++r) {
        for (std::size_t c = 0; c < a[0].size(); ++c) {
            if (r == 0 && c == 0) {
                dp[r][c] = a[r][c];
                continue;
            }
            long long before = inf;
            if (r > 0) {
                before = std::min(before, dp[r - 1][c]);
            }
            if (c > 0) {
                before = std::min(before, dp[r][c - 1]);
            }
            dp[r][c] = before + a[r][c];
        }
    }
    return dp.back().back();
}

int main() {
    assert(minimum({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) == 7);
    assert(minimum({{-2, 1}, {3, -5}}) == -6);
    assert(!minimum({}));
    std::cout << "checks passed\n";
    return 0;
}
