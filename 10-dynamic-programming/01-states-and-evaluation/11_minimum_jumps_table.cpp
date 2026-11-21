/*
 Nonnegative jump bounds; empty array needs 0 jumps. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

dp[i] is minimum jumps needed to reach index i; unreachable entries start
at inf rather than 0.

From index 0 with jump 2, indices 1 and 2 get 1; index 1 can then reach last index
in 2 jumps.

Every route ending at j comes from an earlier reachable i whose jump reaches j;
increasing i finalizes all predecessor options.

O(n^2) time, O(n) storage; compare the earlier linear greedy solution.

This is a baseline for understanding states, not the best bound for this special
reachability problem.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstddef>

std::optional<int> jumps(const std::vector<int>& a) {
    if (a.empty()) {
        return 0;
    }
    const int inf = 1000000;
    std::vector<int> dp(a.size(), inf);
    dp[0] = 0;
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (dp[i] == inf) {
            continue;
        }
        for (std::size_t j = i + 1; j < a.size() && j <= i + static_cast<std::size_t>(a[i]); ++j) {
            dp[j] = std::min(dp[j], dp[i] + 1);
        }
    }
    if (dp.back() == inf) {
        return std::nullopt;
    }
    return dp.back();
}

int main() {
    assert(jumps({2, 3, 1, 1, 4}) == 2);
    assert(!jumps({0, 1}));
    assert(jumps({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
