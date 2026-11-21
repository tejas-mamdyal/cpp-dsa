/*
 0<=L<=R<=10^12, target 0..117; exact long long counts. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

f(pos, sum, tight) counts suffixes reaching exact digit sum target;
range[L, R] subtracts the disjoint prefix[0, L-1] from[0, R].

Digit sum 2 up to 20 occurs at 2,11,20; restricting to 10..20 leaves 11,20.

Tight digit enumeration counts each bounded integer once; prefix subtraction
implements inclusive endpoints exactly.

O(digits*(target+1)*10) time, O(digits*(target+1)) memo.

Handle L 0 before converting L-1 to decimal; negative sign is not a digit state.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

long long solve(const std::string& digits,
                int pos,
                int sum,
                int target,
                bool tight,
                std::vector<std::vector<long long>>& memo) {
    if (sum > target) {
        return 0;
    }
    if (pos == static_cast<int>(digits.size())) {
        return sum == target ? 1 : 0;
    }
    if (!tight && memo[pos][sum] != -1) {
        return memo[pos][sum];
    }
    int limit = tight ? digits[pos] - '0' : 9;
    long long total = 0;
    for (int d = 0; d <= limit; ++d) {
        total += solve(digits, pos + 1, sum + d, target, tight && d == limit, memo);
    }
    if (!tight) {
        memo[pos][sum] = total;
    }
    return total;
}

long long prefix(long long bound, int target) {
    if (bound < 0) {
        return 0;
    }
    std::string digits = std::to_string(bound);
    std::vector<std::vector<long long>> memo(
        digits.size(), std::vector<long long>(static_cast<std::size_t>(target + 1), -1));
    return solve(digits, 0, 0, target, true, memo);
}

long long range(long long left, long long right, int target) {
    assert(left >= 0 && left <= right && right <= 1000000000000LL && target >= 0 && target <= 117);
    return prefix(right, target) - prefix(left - 1, target);
}

int main() {
    assert(range(0, 20, 2) == 3);
    assert(range(10, 20, 2) == 2);
    assert(range(0, 0, 0) == 1);
    assert(range(1, 9, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
