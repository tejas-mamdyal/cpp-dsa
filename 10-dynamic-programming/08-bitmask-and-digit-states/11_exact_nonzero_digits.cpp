/*
 Bound 0..10^12; k 0..13; negative bounds count 0. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

f(pos, used, tight) counts suffixes ending with exactly k nonzero digits;
used>k cannot recover.

Up to 100, one-nonzero numbers are 1..9,10,20,..90,100, total 19.

Each chosen nonzero digit consumes one budget unit; leading zeros consume none
and do not alter the condition.

O(digits*(k+1)*10) time, O(digits*(k+1)) memo.

Including zero depends on k: zero has exactly 0 nonzero digits.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

long long solve(const std::string& digits,
                int pos,
                int used,
                int k,
                bool tight,
                std::vector<std::vector<long long>>& memo) {
    if (used > k) {
        return 0;
    }
    if (pos == static_cast<int>(digits.size())) {
        return used == k ? 1 : 0;
    }
    if (!tight && memo[pos][used] != -1) {
        return memo[pos][used];
    }
    int limit = tight ? digits[pos] - '0' : 9;
    long long total = 0;
    for (int d = 0; d <= limit; ++d) {
        total += solve(digits, pos + 1, used + (d != 0), k, tight && d == limit, memo);
    }
    if (!tight) {
        memo[pos][used] = total;
    }
    return total;
}

long long count(long long bound, int k) {
    if (bound < 0 || k < 0) {
        return 0;
    }
    std::string digits = std::to_string(bound);
    std::vector<std::vector<long long>> memo(
        digits.size(), std::vector<long long>(static_cast<std::size_t>(k + 1), -1));
    return solve(digits, 0, 0, k, true, memo);
}

int main() {
    assert(count(100, 1) == 19);
    assert(count(100, 0) == 1);
    assert(count(9, 2) == 0);
    std::cout << "checks passed\n";
    return 0;
}
