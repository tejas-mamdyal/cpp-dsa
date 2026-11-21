/*
 Positive denominations, amount 0..1000; unlimited reuse. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

dp[s] is minimum number of reusable positive coins totaling exactly s;
unreachable is inf, dp 0=0.

For 1,3,4 at 6, the optimal 3+3 uses 2 rather than greedy 4+1+1 uses 3.

Every nonempty solution has one final coin and an optimal smaller remainder.

O(number coins*amount) time, O(amount) storage.

Minimum-count addition is not the same as counting combinations.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstddef>

std::optional<int> coins(const std::vector<int>& values, int amount) {
    const int inf = 1000000;
    std::vector<int> dp(static_cast<std::size_t>(amount + 1), inf);
    dp[0] = 0;
    for (int sum = 1; sum <= amount; ++sum) {
        for (int coin : values) {
            assert(coin > 0);
            if (coin <= sum && dp[sum - coin] != inf) {
                dp[sum] = std::min(dp[sum], dp[sum - coin] + 1);
            }
        }
    }
    if (dp[amount] == inf) {
        return std::nullopt;
    }
    return dp[amount];
}

int main() {
    assert(coins({1, 3, 4}, 6) == 2);
    assert(!coins({2}, 3));
    assert(coins({}, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
