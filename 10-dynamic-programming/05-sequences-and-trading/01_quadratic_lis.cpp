/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[i] is longest strictly increasing subsequence ending exactly at i;
singleton base 1; answer is max over endpoints.

In 10,9,2,5,3,7,101,18, one length 4 route is 2,3,7,18.

Every non-singleton increasing subsequence ending i has a preceding j<i with
smaller value; try all such final predecessors.

O(n^2) time, O(n) storage.

Using<= computes nondecreasing rather than strictly increasing subsequences.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

std::vector<int> ending(const std::vector<int>& a) {
    std::vector<int> dp(a.size(), 1);
    for (std::size_t i = 0; i < a.size(); ++i) {
        for (std::size_t j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}

int lis(const std::vector<int>& a) {
    auto dp = ending(a);
    return dp.empty() ? 0 : *std::max_element(dp.begin(), dp.end());
}

int main() {
    assert(lis({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(lis({2, 2, 2}) == 1);
    assert(lis({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
