/*
 Bound-1..10^12; negative prefix count 0; include number 0. Unless a different bound
is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

f(pos, rem, tight) counts suffix assignments whose final digit-sum
remainder is 0; leading zeros do not change sum, so a separate started flag is unnecessary.

Up to 20, the accepted values are 0,3,6,9,12,15,18, total 7.

Every integer 0..bound has one fixed-width padded representation; digit choices
respecting tightness enumerate it once.

O(number digits*3*10) time, O(number digits*3) memo/stack.

The cache excludes tight states because their allowed suffix depends on the bound
prefix.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <array>

long long solve(const std::string& digits,
                int pos,
                int rem,
                bool tight,
                std::vector<std::array<long long, 3>>& memo) {
    if (pos == static_cast<int>(digits.size())) {
        return rem == 0 ? 1 : 0;
    }
    if (!tight && memo[pos][rem] != -1) {
        return memo[pos][rem];
    }
    int limit = tight ? digits[pos] - '0' : 9;
    long long total = 0;
    for (int d = 0; d <= limit; ++d) {
        total += solve(digits, pos + 1, (rem + d) % 3, tight && d == limit, memo);
    }
    if (!tight) {
        memo[pos][rem] = total;
    }
    return total;
}

long long count(long long bound) {
    if (bound < 0) {
        return 0;
    }
    std::string digits = std::to_string(bound);
    std::vector<std::array<long long, 3>> memo(digits.size(), std::array<long long, 3>{-1, -1, -1});
    return solve(digits, 0, 0, true, memo);
}

int main() {
    assert(count(20) == 7);
    assert(count(0) == 1);
    for (int n = 0; n <= 200; ++n) {
        long long expected = 0;
        for (int x = 0; x <= n; ++x) {
            int sum = 0;
            for (int v = x; v > 0; v /= 10) {
                sum += v % 10;
            }
            expected += sum % 3 == 0;
        }
        assert(count(n) == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
