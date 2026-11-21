/*
 At most 30 nonnegative balloon values<=1000; virtual outside values 1. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[l][r] is maximum reward for bursting all balloons strictly between two
still-present boundary balloons.

For 3,1,5,8, an optimum bursts 1 then 5 then 3 then 8 for 167.

If last is the final interior balloon, it sees the unchanged boundary values;
earlier left/right work is independent.

O(n^3) time, O(n^2) table.

Choosing the first burst does not leave fixed neighboring values for subproblems.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long balloons(const std::vector<int>& values) {
    std::vector<int> a{1};
    a.insert(a.end(), values.begin(), values.end());
    a.push_back(1);
    int n = static_cast<int>(a.size());
    std::vector<std::vector<long long>> dp(a.size(), std::vector<long long>(a.size(), 0));
    for (int gap = 2; gap < n; ++gap) {
        for (int left = 0; left + gap < n; ++left) {
            int right = left + gap;
            for (int last = left + 1; last < right; ++last) {
                dp[left][right] =
                    std::max(dp[left][right],
                             dp[left][last] + dp[last][right] + 1LL * a[left] * a[last] * a[right]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    assert(balloons({3, 1, 5, 8}) == 167);
    assert(balloons({}) == 0);
    assert(balloons({2}) == 2);
    std::cout << "checks passed\n";
    return 0;
}
