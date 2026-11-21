/*
 Nonnegative values, total<=2000; empty-group convention allowed. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

If total is even, a target total/2 subset determines its complementary
group.

1,5,11,5 totals 22; the subset 11 balances the complement 1,5,5.

Equal groups each have half the total, and every half-total subset gives such a
partition.

O(n*total) time, O(total) storage.

This convention permits empty groups for empty/all-zero input; state a nonempty-group
requirement separately.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>
#include <numeric>

bool subset(const std::vector<int>& a, int target) {
    assert(target >= 0 && target <= 1000);
    std::vector<bool> dp(static_cast<std::size_t>(target + 1), false);
    dp[0] = true;
    for (int x : a) {
        assert(x >= 0);
        for (int sum = target; sum >= x; --sum) {
            dp[sum] = dp[sum] || dp[sum - x];
        }
    }
    return dp[target];
}

bool equal(const std::vector<int>& a) {
    int total = std::accumulate(a.begin(), a.end(), 0);
    if (total % 2 != 0) {
        return false;
    }
    return subset(a, total / 2);
}

int main() {
    assert(equal({1, 5, 11, 5}));
    assert(!equal({1, 2, 5}));
    assert(equal({}));
    std::cout << "checks passed\n";
    return 0;
}
