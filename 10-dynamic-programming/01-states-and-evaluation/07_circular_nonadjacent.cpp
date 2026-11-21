/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

A circular valid selection cannot include both endpoints; solve ranges
excluding last or excluding first.

2,3,2 cannot take both 2 endpoints; each linear case returns 3.

Every valid circular solution excludes at least one endpoint, so it belongs to
one covered linear subproblem.

O(n) time, O(1) auxiliary.

Singleton endpoints refer to the same item; handle that case separately.
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

long long circular(const std::vector<int>& a) {
    if (a.empty()) {
        return 0;
    }
    if (a.size() == 1) {
        return std::max(0, a[0]);
    }
    return std::max(robRange(a, 0, a.size() - 1), robRange(a, 1, a.size()));
}

int main() {
    assert(circular({2, 3, 2}) == 3);
    assert(circular({1, 2, 3, 1}) == 4);
    assert(circular({}) == 0);
    assert(circular({-1}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
