/*
 Nonnegative values, total<=2000.

dp[s] marks achievable subset sums; the complementary difference is
abs(total-2s), minimized nearest half.

Total 23 can reach 11 or 12, so best difference 1.

Every two-way split is a subset and its complement; testing all reachable sums
covers every split.

O(n*total) time, O(total) space.

The closest numerical half may not be reachable.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>
#include <numeric>

int difference(const std::vector<int>& a) {
    int total = std::accumulate(a.begin(), a.end(), 0);
    std::vector<bool> dp(static_cast<std::size_t>(total + 1), false);
    dp[0] = true;
    for (int x : a) {
        for (int sum = total; sum >= x; --sum) {
            dp[sum] = dp[sum] || dp[sum - x];
        }
    }
    for (int sum = total / 2; sum >= 0; --sum) {
        if (dp[sum]) {
            return total - 2 * sum;
        }
    }
    return 0;
}

int main() {
    assert(difference({1, 6, 11, 5}) == 1);
    assert(difference({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
