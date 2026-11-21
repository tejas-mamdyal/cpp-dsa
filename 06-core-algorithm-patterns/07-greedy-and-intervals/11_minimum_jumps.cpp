/*
 Nonnegative jumps; empty/singleton requires 0; unreachable absent.

IDEA AND STATE: Expand the farthest endpoint of the current jump-count layer; increment only
when its boundary is reached.

TRACE: 2,3,1,1,4 ->2.

The first jump layer ends at2;scanning that layer reaches4,so the next boundary reaches the
destination in two jumps.

All indices up to the current boundary are reachable in at most the current
number of jumps; one expansion covers all next-layer destinations.

O(n) time, O(1) space.

If a layer cannot extend, return absence instead of counting another jump.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> jumps(const std::vector<int>& a) {
    if (a.size() < 2) {
        return 0;
    }
    long long end = 0;
    long long far = 0;
    int count = 0;
    for (int i = 0; i < static_cast<int>(a.size()) - 1; ++i) {
        assert(a[i] >= 0);
        far = std::max(far, 1LL * i + a[i]);
        if (i == end) {
            if (far == end) {
                return std::nullopt;
            }
            ++count;
            end = far;
            if (end >= static_cast<long long>(a.size()) - 1) {
                return count;
            }
        }
    }
    return std::nullopt;
}

int main() {
    assert(jumps({2, 3, 1, 1, 4}) == 2);
    assert(!jumps({3, 2, 1, 0, 4}));
    assert(jumps({}) == 0);
    assert(jumps({0}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
