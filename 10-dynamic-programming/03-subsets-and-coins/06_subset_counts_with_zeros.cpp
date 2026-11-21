/*
 n<=30, nonnegative values, target 0..1000; positional counts exact in long long.

dp[s] counts positional subsets totaling s; skip and take choices add,
even if x 0 makes both predecessor sums equal.

Two zeros double dp 0 from 1 to 2 to 4; adding 1 creates four target 1 subsets.

Each item gives disjoint index-choice alternatives, so equal numeric sums still
contribute separate counts.

O(n*T) time, O(T) storage; at most 2^30 subsets.

Special-casing target 0 as always 1 loses zero selections.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long count(const std::vector<int>& a, int target) {
    std::vector<long long> dp(static_cast<std::size_t>(target + 1), 0);
    dp[0] = 1;
    for (int x : a) {
        assert(x >= 0);
        for (int sum = target; sum >= x; --sum) {
            dp[sum] += dp[sum - x];
        }
    }
    return dp[target];
}

int main() {
    assert(count({0, 0, 1}, 1) == 4);
    assert(count({0, 0}, 0) == 4);
    assert(count({}, 0) == 1);
    std::cout << "checks passed\n";
    return 0;
}
