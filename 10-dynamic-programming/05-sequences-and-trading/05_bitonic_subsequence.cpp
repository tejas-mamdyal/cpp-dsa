/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

left[i] is increasing length ending at peak i; right[i] is decreasing
length starting there, computed by reversed LIS.

A peak 10 can join increasing 1,2,10 with decreasing 10,5,2,1 for total 6 after
removing the duplicate peak.

Any bitonic subsequence has a peak; maximizing its two independent ordered arms
and testing all peaks is complete.

O(n^2) time, O(n) auxiliary.

This convention permits a one-sided monotone arm; requiring both arms changes the
eligibility test.
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

int bitonic(const std::vector<int>& a) {
    auto left = ending(a);
    std::vector<int> reversed(a.rbegin(), a.rend());
    auto right = ending(reversed);
    std::reverse(right.begin(), right.end());
    int best = 0;
    for (std::size_t i = 0; i < a.size(); ++i) {
        best = std::max(best, left[i] + right[i] - 1);
    }
    return best;
}

int main() {
    assert(bitonic({1, 11, 2, 10, 4, 5, 2, 1}) == 6);
    assert(bitonic({1, 2, 3}) == 3);
    assert(bitonic({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
