/*
 Nonnegative values; target 0..1000; return absence or selected indices. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[i][s] is exact feasibility using first i positions; prefer skipping a
tie to reconstruct one deterministic witness.

For 3,4,2, target 6, the final 2 is necessary, leaving 4 which selects the second
item.

Backward decisions follow a true predecessor until sum 0 at the initial layer;
indices decrease and never repeat.

O(n*T) time/storage plus O(n) witness.

Return indices when repeated values must remain distinguishable.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstddef>

std::optional<std::vector<int>> witness(const std::vector<int>& a, int target) {
    std::vector<std::vector<bool>> dp(
        a.size() + 1, std::vector<bool>(static_cast<std::size_t>(target + 1), false));
    dp[0][0] = true;
    for (std::size_t i = 1; i <= a.size(); ++i) {
        for (int sum = 0; sum <= target; ++sum) {
            dp[i][sum] = dp[i - 1][sum] || (a[i - 1] <= sum && dp[i - 1][sum - a[i - 1]]);
        }
    }
    if (!dp.back()[target]) {
        return std::nullopt;
    }
    std::vector<int> indices;
    for (std::size_t i = a.size(); i > 0; --i) {
        if (dp[i - 1][target]) {
            continue;
        }
        indices.push_back(static_cast<int>(i - 1));
        target -= a[i - 1];
    }
    std::reverse(indices.begin(), indices.end());
    return indices;
}

int main() {
    std::vector<int> a{3, 4, 2};
    auto selected = witness(a, 6);
    assert(selected);
    int sum = 0;
    for (int i : *selected) {
        sum += a[i];
    }
    assert(sum == 6);
    assert(witness({}, 0)->empty());
    assert(!witness({2}, 3));
    std::cout << "checks passed\n";
    return 0;
}
