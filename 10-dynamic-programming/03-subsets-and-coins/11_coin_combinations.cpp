/*
 Distinct positive denominations, amount 0..30; exact combination counts fit long
long.

After processing a coin type, dp[s] counts combinations using only
processed types; current type can repeat via ascending sums.

Amount 3 with 1,2 counts 1+1+1 and 1+2 only once each.

Every combination has a unique count of the current final coin type; coin order
is never permuted by the outer loop.

O(k*amount) time, O(amount) storage.

Repeated denomination entries would double-count indistinguishable types.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long combinations(const std::vector<int>& coins, int amount) {
    std::vector<long long> dp(static_cast<std::size_t>(amount + 1), 0);
    dp[0] = 1;
    for (int coin : coins) {
        assert(coin > 0);
        for (int sum = coin; sum <= amount; ++sum) {
            dp[sum] += dp[sum - coin];
        }
    }
    return dp[amount];
}

int main() {
    assert(combinations({1, 2, 5}, 5) == 4);
    assert(combinations({}, 0) == 1);
    assert(combinations({2}, 3) == 0);
    std::cout << "checks passed\n";
    return 0;
}
