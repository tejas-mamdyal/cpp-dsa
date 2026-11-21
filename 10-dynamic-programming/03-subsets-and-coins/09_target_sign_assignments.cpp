/*
CONVERT PLUS/MINUS LABELS INTO A SUBSET-COUNT EQUATION

 n<=30, nonnegative values, total<=2000, target magnitude<=2000. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

Positive-signed positions total P, negative total N; P-N=target and
P+N=total imply P=(total+target)/2.

Five ones at target 3 require four positive positions; choose the one negative
position in five ways.

Each sign assignment uniquely identifies its positive-position subset, including
distinct zero sign choices.

O(n*total) time, O(total) storage.

Check magnitude and parity before allocating the reduced sum table.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <numeric>

long long signs(const std::vector<int>& a, int target) {
    int total = std::accumulate(a.begin(), a.end(), 0);
    if (std::abs(target) > total || (total + target) % 2 != 0) {
        return 0;
    }
    int desired = (total + target) / 2;
    std::vector<long long> dp(static_cast<std::size_t>(desired + 1), 0);
    dp[0] = 1;
    for (int x : a) {
        for (int sum = desired; sum >= x; --sum) {
            dp[sum] += dp[sum - x];
        }
    }
    return dp[desired];
}

int main() {
    assert(signs({1, 1, 1, 1, 1}, 3) == 5);
    assert(signs({0, 0}, 0) == 4);
    assert(signs({1}, 2) == 0);
    std::cout << "checks passed\n";
    return 0;
}
