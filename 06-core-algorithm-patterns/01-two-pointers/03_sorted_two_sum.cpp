/*
 Nondecreasing vector; return two distinct indices whose sum equals target, or absence.

IDEA AND STATE: If endpoint sum is too small, advance left; too large, retreat right.

TRACE: 1,2,4,7 target 9 ->indices 1,3.

At indices0,3 the sum is8<9,so advance left;indices1,3 sum to9 and stop.

With right fixed, no value at or left of a too-small left endpoint can work; the
symmetric argument excludes a too-large right endpoint.

O(n) time, O(1) space.

Sorting changes original indices; this helper explicitly accepts sorted input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>

std::optional<std::pair<int, int>> twoSum(const std::vector<int>& a, long long target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    while (left < right) {
        long long sum = 1LL * a[left] + a[right];
        if (sum == target) {
            return std::pair<int, int>{left, right};
        }
        if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return std::nullopt;
}

int main() {
    auto result = twoSum({1, 2, 4, 7}, 9);
    assert((result == std::optional<std::pair<int, int>>{{1, 3}}));
    assert(twoSum({3, 3}, 6));
    assert(!twoSum({3}, 6));
    assert(!twoSum({}, 0));
    std::cout << "checks passed\n";
    return 0;
}
