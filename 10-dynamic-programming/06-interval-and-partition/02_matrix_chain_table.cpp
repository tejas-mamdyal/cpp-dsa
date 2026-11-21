/*
 Positive dimensions<=1000, at most 30 matrices; cost-only version without
unnecessary expression strings.

dp[left][right] is minimum scalar multiplication cost for that inclusive
matrix interval; single-matrix cost 0.

Two-matrix subcosts 1500 and 9000 are finalized before the three-matrix interval
chooses total 4500.

Each possible final split combines two strictly shorter finalized intervals and
the correctly dimensioned final product.

O(n^3) time, O(n^2) table.

Increasing left index alone is not a valid dependency order; process interval length
first.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstddef>

long long chainCost(const std::vector<int>& d) {
    if (d.size() < 2) {
        return 0;
    }
    int n = static_cast<int>(d.size()) - 1;
    std::vector<std::vector<long long>> dp(static_cast<std::size_t>(n),
                                           std::vector<long long>(static_cast<std::size_t>(n), 0));
    for (int length = 2; length <= n; ++length) {
        for (int left = 0; left + length <= n; ++left) {
            int right = left + length - 1;
            dp[left][right] = std::numeric_limits<long long>::max();
            for (int split = left; split < right; ++split) {
                long long candidate = dp[left][split] + dp[split + 1][right]
                                      + 1LL * d[left] * d[split + 1] * d[right + 1];
                dp[left][right] = std::min(dp[left][right], candidate);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    assert(chainCost({10, 30, 5, 60}) == 4500);
    assert(chainCost({5, 10, 3}) == 150);
    assert(chainCost({10, 20}) == 0);
    assert(chainCost({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
