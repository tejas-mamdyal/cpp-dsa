/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[i] is the maximum sum among the first i values with no adjacent
selections; empty selection is allowed.

For 2,7,9, the best prefixes are 2,7,11; selecting 9 combines with 2 rather than
adjacent 7.

An optimum skips the last value or takes it and then excludes its neighbor.

O(n) time, O(1) auxiliary.

A nonempty required answer would need different initialization for all-negative data.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

long long robRange(const std::vector<int>& a, std::size_t left, std::size_t right) {
    long long two = 0;
    long long one = 0;
    for (std::size_t i = left; i < right; ++i) {
        long long next = std::max(one, two + a[i]);
        two = one;
        one = next;
    }
    return one;
}

int main() {
    assert(robRange({2, 7, 9, 3, 1}, 0, 5) == 12);
    assert(robRange({-5, -2}, 0, 2) == 0);
    assert(robRange({}, 0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
