/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[i] is maximum sum of a nonempty strictly increasing subsequence ending
i; singleton a[i] is a real base candidate.

1,2,3,100 sums 106, beating 1,101 sum 102 despite a different length.

An optimum ends at i alone or extends a smaller earlier endpoint.

O(n^2) time, O(n) storage.

Zero initialization would invent an empty answer for all-negative input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstddef>

std::optional<long long> maximumSum(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    std::vector<long long> dp(a.begin(), a.end());
    for (std::size_t i = 0; i < a.size(); ++i) {
        for (std::size_t j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                dp[i] = std::max(dp[i], dp[j] + a[i]);
            }
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    assert(maximumSum({1, 101, 2, 3, 100, 4, 5}) == 106);
    assert(maximumSum({-5, -2}) == -2);
    assert(!maximumSum({}));
    std::cout << "checks passed\n";
    return 0;
}
