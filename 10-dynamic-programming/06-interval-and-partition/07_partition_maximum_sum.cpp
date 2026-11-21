/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[i] is maximum transformed sum after partitioning first i positions into
blocks of length<=k; each block replaces all entries by its maximum.

For the standard array, blocks 1,15,7;9;2,5,10 contribute 45+9+30=84.

Every complete partition has a final block; its contribution is fixed by its
maximum and length, plus an optimal earlier partition.

O(n*k) time, O(n) table.

Initialize nonempty prefix optima negatively when values may be negative; zero is not
a legal skipped prefix.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstddef>

long long partition(const std::vector<int>& a, int k) {
    assert(k >= 1);
    std::vector<long long> dp(a.size() + 1, 0);
    for (std::size_t end = 1; end <= a.size(); ++end) {
        dp[end] = std::numeric_limits<long long>::lowest() / 4;
        int high = std::numeric_limits<int>::min();
        for (std::size_t size = 1; size <= static_cast<std::size_t>(k) && size <= end; ++size) {
            high = std::max(high, a[end - size]);
            dp[end] = std::max(dp[end], dp[end - size] + 1LL * high * static_cast<long long>(size));
        }
    }
    return dp.back();
}

int main() {
    assert(partition({1, 15, 7, 9, 2, 5, 10}, 3) == 84);
    assert(partition({-2, -1}, 2) == -2);
    assert(partition({}, 3) == 0);
    std::cout << "checks passed\n";
    return 0;
}
