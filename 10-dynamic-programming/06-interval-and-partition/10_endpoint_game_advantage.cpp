/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[l][r] is maximum current-player score minus opponent score on the
remaining interval, both playing optimally.

For 1,5,2, the opponent can secure 5, so first-player advantage is-2.

Taking an endpoint earns its value then hands the remaining game to the opponent,
whose best advantage is subtracted.

O(n^2) time/storage.

Using addition for the opponent term incorrectly lets both turns optimize for the
same player.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long advantage(const std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    if (n == 0) {
        return 0;
    }
    std::vector<std::vector<long long>> dp(a.size(), std::vector<long long>(a.size(), 0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = a[i];
    }
    for (int length = 2; length <= n; ++length) {
        for (int l = 0; l + length <= n; ++l) {
            int r = l + length - 1;
            dp[l][r] = std::max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    assert(advantage({1, 5, 2}) == -2);
    assert(advantage({1, 5, 233, 7}) == 222);
    assert(advantage({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
