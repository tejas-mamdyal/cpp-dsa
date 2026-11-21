/*
 Bound 0..10^12; count zero occurrences in natural decimal representations, including
one zero for number 0.

Return(ways, total actual zeros), with started marking whether a real
nonzero digit has begun. The all-padding path represents number 0 and contributes one written
zero at the base.

Up to 20, the written zeros occur in 0,10,20, total 3; leading padding for single
digits contributes none.

Only zeros after starting are written in ordinary multi-digit numerals; the
unique never-started path is handled as the numeral 0.

O(digits*2*10) time, O(digits*2) memo.

Counting every padded zero badly overcounts shorter numbers.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
#include <utility>
#include <array>

using Counts = std::pair<long long, long long>;

Counts solve(const std::string& digits,
             int pos,
             bool started,
             bool tight,
             std::vector<std::array<std::optional<Counts>, 2>>& memo) {
    if (pos == static_cast<int>(digits.size())) {
        return {1, started ? 0 : 1};
    }
    if (!tight && memo[pos][started]) {
        return *memo[pos][started];
    }
    int limit = tight ? digits[pos] - '0' : 9;
    long long ways = 0;
    long long zeros = 0;
    for (int d = 0; d <= limit; ++d) {
        bool nextStarted = started || d != 0;
        auto child = solve(digits, pos + 1, nextStarted, tight && d == limit, memo);
        ways += child.first;
        zeros += child.second;
        if (started && d == 0) {
            zeros += child.first;
        }
    }
    Counts out{ways, zeros};
    if (!tight) {
        memo[pos][started] = out;
    }
    return out;
}

long long zeros(long long bound) {
    if (bound < 0) {
        return 0;
    }
    std::string digits = std::to_string(bound);
    std::vector<std::array<std::optional<Counts>, 2>> memo(digits.size());
    return solve(digits, 0, false, true, memo).second;
}

int main() {
    assert(zeros(0) == 1);
    assert(zeros(10) == 2);
    assert(zeros(20) == 3);
    assert(zeros(100) == 12);
    std::cout << "checks passed\n";
    return 0;
}
