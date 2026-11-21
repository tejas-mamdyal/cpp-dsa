/*
 n 0..18; exact long long counts.

dp[i] counts permutations of i labeled items with no fixed point. Pick the
partner of item 1; the partner either returns to 1 or does not.

dp 2=1, dp 3=2, dp 4=3*(2+1)=9.

There are i-1 partner choices; the two cases reduce to derangements on i-2 or i-1
labels via contracting the chosen edge.

O(n) time, O(n) storage; bound 18 keeps counts representable.

This counts labeled permutations, not circular seatings.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long derangements(int n) {
    assert(n >= 0 && n <= 18);
    std::vector<long long> dp(static_cast<std::size_t>(n + 1), 0);
    dp[0] = 1;
    if (n >= 1) {
        dp[1] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

int main() {
    assert(derangements(0) == 1);
    assert(derangements(1) == 0);
    assert(derangements(4) == 9);
    std::cout << "checks passed\n";
    return 0;
}
