/*
 At most 30 nonnegative bottle base prices; all bottles sold, one endpoint per year.

dp[l][r] is maximum revenue from remaining endpoint-accessible bottles;
year=n-(r-l+1)+1, so no separate year dimension is needed.

The standard five-bottle fixture optimally earns 50 across years 1..5.

The next sale must be the left or right endpoint; each leaves one strictly
smaller interval with the next implied year.

O(n^2) time/storage.

Adding a redundant year dimension wastes states when it is already implied by
interval length.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long wine(const std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    if (n == 0) {
        return 0;
    }
    std::vector<std::vector<long long>> dp(a.size(), std::vector<long long>(a.size(), 0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1LL * n * a[i];
    }
    for (int length = 2; length <= n; ++length) {
        int year = n - length + 1;
        for (int left = 0; left + length <= n; ++left) {
            int right = left + length - 1;
            dp[left][right] = std::max(1LL * year * a[left] + dp[left + 1][right],
                                       1LL * year * a[right] + dp[left][right - 1]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    assert(wine({2, 3, 5, 1, 4}) == 50);
    assert(wine({7}) == 7);
    assert(wine({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
