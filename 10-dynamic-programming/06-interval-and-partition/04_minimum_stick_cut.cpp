/*
 Positive stick length<=1000; at most 30 valid interior requested positions;
duplicate positions collapse.

dp[l][r] is minimum cost to perform all requested interior cuts between
boundary positions cuts[l], cuts[r].

Cutting at 3 first splits a length 7 stick, then optimally cuts the two smaller
pieces, total 16.

The first cut pays current segment length and partitions all later work into
independent left/right interiors.

O(m^3) time, O(m^2) table after sorting.

Cut indices are not physical positions; the charged cost uses boundary coordinates.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

long long cutting(int length, std::vector<int> cuts) {
    for (int x : cuts) {
        assert(x > 0 && x < length);
    }
    cuts.push_back(0);
    cuts.push_back(length);
    std::sort(cuts.begin(), cuts.end());
    cuts.erase(std::unique(cuts.begin(), cuts.end()), cuts.end());
    int n = static_cast<int>(cuts.size());
    std::vector<std::vector<long long>> dp(cuts.size(), std::vector<long long>(cuts.size(), 0));
    for (int gap = 2; gap < n; ++gap) {
        for (int left = 0; left + gap < n; ++left) {
            int right = left + gap;
            dp[left][right] = std::numeric_limits<long long>::max();
            for (int k = left + 1; k < right; ++k) {
                dp[left][right] = std::min(dp[left][right],
                                           cuts[right] - cuts[left] + dp[left][k] + dp[k][right]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    assert(cutting(7, {1, 3, 4, 5}) == 16);
    assert(cutting(9, {}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
