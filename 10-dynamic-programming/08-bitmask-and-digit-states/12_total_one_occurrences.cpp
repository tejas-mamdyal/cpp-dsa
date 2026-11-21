/*
 Bound 0..10^12; natural decimal numerals; leading zeros never contribute ones.

A state returns(ways, total ones) among its suffix completions; if the
current digit is 1, it contributes one occurrence for each child completion.

Up to 13, ones appear in 1,10,11 twice,12 and 13, total 6.

Partition numbers by current digit; sum child occurrences and add
current-position contributions multiplied by the number of suffixes.

O(digits*10) time, O(digits) non-tight memo/stack.

Counting numbers containing a 1 is not the same as counting all 1 occurrences.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
#include <utility>

std::pair<long long, long long>
solve(const std::string& digits,
      int pos,
      bool tight,
      std::vector<std::optional<std::pair<long long, long long>>>& memo) {
    if (pos == static_cast<int>(digits.size())) {
        return {1, 0};
    }
    if (!tight && memo[pos]) {
        return *memo[pos];
    }
    int limit = tight ? digits[pos] - '0' : 9;
    long long ways = 0;
    long long ones = 0;
    for (int d = 0; d <= limit; ++d) {
        auto child = solve(digits, pos + 1, tight && d == limit, memo);
        ways += child.first;
        ones += child.second;
        if (d == 1) {
            ones += child.first;
        }
    }
    auto out = std::pair<long long, long long>{ways, ones};
    if (!tight) {
        memo[pos] = out;
    }
    return out;
}

long long ones(long long bound) {
    if (bound < 0) {
        return 0;
    }
    std::string digits = std::to_string(bound);
    std::vector<std::optional<std::pair<long long, long long>>> memo(digits.size());
    return solve(digits, 0, true, memo).second;
}

int main() {
    assert(ones(13) == 6);
    assert(ones(0) == 0);
    assert(ones(99) == 20);
    std::cout << "checks passed\n";
    return 0;
}
