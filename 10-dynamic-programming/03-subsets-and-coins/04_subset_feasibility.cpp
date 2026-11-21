/*
 At most 30 nonnegative values; target 0..1000.

dp[s] means some subset of processed positions totals exactly s; only sum
0 is initially reachable.

Values 3,4,2 can reach 9; values 2,4 cannot reach odd 3.

Each item is skipped or added once to an earlier-item reachable sum.

O(n*T) time, O(T) storage.

Signed values need another sum representation; negative indices are not supported
here.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

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

int main() {
    assert(subset({3, 34, 4, 12, 5, 2}, 9));
    assert(!subset({2, 4}, 3));
    assert(subset({}, 0));
    std::cout << "checks passed\n";
    return 0;
}
