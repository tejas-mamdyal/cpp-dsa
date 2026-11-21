/*
 n<=30 signed values; count positional subsets summing to target. Unless narrowed, at
most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic
owned structures; exponential searches use the smaller bounds stated here. No input; keep
assertions enabled. Success prints checks passed.

Generate sums of each half, sort one half, then count target-left with
equal_range. Baseline inspects all 2^n subsets.

For 1,2,3, target 3, left sums 0,1; right sums 0,2,3,5 yield matches 3 and 2, total 2.

Every full subset uniquely splits into a left and right subset; equal_range counts
all matching multiplicities.

O((n+1)*2^(ceil(n/2))) time and O(2^(ceil(n/2))) space.

Deduplicating half sums would lose distinct positional subsets.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

long long countTarget(const std::vector<int>& a, long long target) {
    std::size_t mid = a.size() / 2;
    auto left = halfSums(a, 0, mid);
    auto right = halfSums(a, mid, a.size());
    std::sort(right.begin(), right.end());
    long long count = 0;
    for (long long sum : left) {
        auto bounds = std::equal_range(right.begin(), right.end(), target - sum);
        count += bounds.second - bounds.first;
    }
    return count;
}

int main() {
    assert(countTarget({1, 2, 3}, 3) == 2);
    assert(countTarget({0, 0}, 0) == 4);
    assert(countTarget({}, 0) == 1);
    assert(countTarget({5, -4}, 1) == 1);
    std::cout << "checks passed\n";
    return 0;
}
