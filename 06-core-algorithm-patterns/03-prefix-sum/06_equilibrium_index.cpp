/*
 Return the first index whose excluded left/right sums are equal, or absence.

IDEA AND STATE: Maintain left sum; right equals total-left-current.

TRACE: 1,7,3,6,5,6 ->index 3.

Total is28;at index3,left is11 and right is28-11-6=11,so index3 qualifies.

Total partitions into left, current, right, so the comparison is exact.

O(n) time, O(1) working space.

The current element belongs to neither side.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <optional>

std::optional<int> equilibrium(const std::vector<int>& a) {
    long long total = std::accumulate(a.begin(), a.end(), 0LL);
    long long left = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (left == total - left - a[i]) {
            return i;
        }
        left += a[i];
    }
    return std::nullopt;
}

int main() {
    assert(equilibrium({1, 7, 3, 6, 5, 6}) == 3);
    assert(equilibrium({7}) == 0);
    assert(!equilibrium({}));
    assert(!equilibrium({1, 2, 3}));
    std::cout << "checks passed\n";
    return 0;
}
