/*
 n 0..60.

dp[i] counts ordered routes totaling exactly i; increasing i makes both
predecessors available.

dp 0..5 are 1,1,2,3,5,8.

Induction on i applies the same first-step decomposition after predecessor
entries are correct.

O(n) time, O(n) table; no recursion.

Do not read dp[-1] for the first position.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long ways(int n) {
    assert(n >= 0 && n <= 60);
    std::vector<long long> dp(static_cast<std::size_t>(n + 1), 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i >= 2) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int main() {
    assert(ways(0) == 1);
    assert(ways(1) == 1);
    assert(ways(5) == 8);
    std::cout << "checks passed\n";
    return 0;
}
