/*
 Distinct positive denominations, amount 0..30; ordered sequence counts exact in long
long.

dp[s] counts ordered coin sequences totaling s; each choice of final coin
creates a different sequence family.

Amount 3 with 1,2 counts 1,1,1;1,2;2,1, total 3.

Each nonempty sequence has a unique final value; removing it leaves any valid
smaller sequence.

O(k*amount) time, O(amount) storage.

Swapping the loop nesting changes what is counted, not merely performance.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long sequences(const std::vector<int>& coins, int amount) {
    std::vector<long long> dp(static_cast<std::size_t>(amount + 1), 0);
    dp[0] = 1;
    for (int sum = 1; sum <= amount; ++sum) {
        for (int coin : coins) {
            assert(coin > 0);
            if (coin <= sum) {
                dp[sum] += dp[sum - coin];
            }
        }
    }
    return dp[amount];
}

int main() {
    assert(sequences({1, 2}, 3) == 3);
    assert(sequences({}, 0) == 1);
    assert(sequences({2}, 3) == 0);
    std::cout << "checks passed\n";
    return 0;
}
