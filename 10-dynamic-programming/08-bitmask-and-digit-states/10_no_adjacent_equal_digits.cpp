/*
 Count integers 0..bound, bound<=10^12; number 0 is valid. Unless a different bound
is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

previous 10 means no nonleading digit has started; otherwise 0..9
remembers the last actual digit. tight handles the upper bound.

Leading padded zeros before 7 are ignored;11 is excluded, while 101 is valid.

The previous actual digit is exactly the information needed to reject equal
adjacency; ignoring leading padding preserves natural numeral semantics.

O(digits*11*10) time, O(digits*11) memo.

Treating padding zeros as actual digits would exclude every shorter number with
multiple leading zeros.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <array>

long long solve(const std::string& digits,
                int pos,
                int previous,
                bool tight,
                std::vector<std::array<long long, 11>>& memo) {
    if (pos == static_cast<int>(digits.size())) {
        return 1;
    }
    if (!tight && memo[pos][previous] != -1) {
        return memo[pos][previous];
    }
    int limit = tight ? digits[pos] - '0' : 9;
    long long total = 0;
    for (int d = 0; d <= limit; ++d) {
        if (previous != 10 && d == previous) {
            continue;
        }
        int next = previous == 10 && d == 0 ? 10 : d;
        total += solve(digits, pos + 1, next, tight && d == limit, memo);
    }
    if (!tight) {
        memo[pos][previous] = total;
    }
    return total;
}

long long count(long long bound) {
    if (bound < 0) {
        return 0;
    }
    std::string digits = std::to_string(bound);
    std::vector<std::array<long long, 11>> memo(digits.size());
    for (auto& row : memo) {
        row.fill(-1);
    }
    return solve(digits, 0, 10, true, memo);
}

int main() {
    assert(count(20) == 20);
    assert(count(100) == 91);
    assert(count(0) == 1);
    std::cout << "checks passed\n";
    return 0;
}
