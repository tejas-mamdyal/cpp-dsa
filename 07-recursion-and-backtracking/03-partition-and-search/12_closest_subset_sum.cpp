/*
 n<=30 signed values; target magnitude<=1000000; minimize absolute target difference
including empty subset. Unless narrowed, at most 100 nodes/elements with values in
[-1000,1000]. Recursive examples assume valid acyclic owned structures; exponential searches
use the smaller bounds stated here. No input; keep assertions enabled. Success prints checks
passed.

Sort right-half sums; for each left sum, lower_bound finds the first
right>=target-left. Only it and its predecessor can be closest.

5,-7,3,5 with goal 6 achieves 0 difference by choosing 5,-7,3,5.

All full subsets split uniquely; in a sorted sequence the nearest target is one of
its two bracketing values.

O((n+1)*2^(ceil(n/2))) time and exponential half-sum storage.

Check begin/end before moving the iterator; negative sums are legal.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <cstddef>

std::vector<long long> halfSums(const std::vector<int>& a, std::size_t first, std::size_t last) {
    std::vector<long long> sums{0};
    for (std::size_t i = first; i < last; ++i) {
        std::size_t size = sums.size();
        for (std::size_t j = 0; j < size; ++j) {
            sums.push_back(sums[j] + a[i]);
        }
    }
    return sums;
}

long long closest(const std::vector<int>& a, long long goal) {
    auto left = halfSums(a, 0, a.size() / 2);
    auto right = halfSums(a, a.size() / 2, a.size());
    std::sort(right.begin(), right.end());
    long long best = std::numeric_limits<long long>::max();
    for (long long x : left) {
        auto it = std::lower_bound(right.begin(), right.end(), goal - x);
        if (it != right.end()) {
            best = std::min(best, std::abs(x + *it - goal));
        }
        if (it != right.begin()) {
            --it;
            best = std::min(best, std::abs(x + *it - goal));
        }
    }
    return best;
}

int main() {
    assert(closest({5, -7, 3, 5}, 6) == 0);
    assert(closest({}, 7) == 7);
    assert(closest({1, 2}, 10) == 7);
    std::cout << "checks passed\n";
    return 0;
}
