/*
 Positive piles; nonnegative hours; empty requires speed 0; nonempty needs at least one
hour per pile.

IDEA AND STATE: Hours at speed r are sum(ceil(p/r)); find the first feasible speed.

TRACE: 3,6,7,11 with 8 hours ->4.

Speed3 uses1+2+3+4=10 hours;speed4 uses1+2+2+3=8,so minimum speed is4.

Every term is nonincreasing with speed, so feasibility has one false-to-true
boundary.

O(n log M) time, O(1) space.

Use (p-1)/r+1 to avoid overflow in p+r-1.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> speed(const std::vector<int>& piles, long long hours) {
    assert(hours >= 0);
    if (piles.empty()) {
        return 0;
    }
    if (hours < static_cast<long long>(piles.size())) {
        return std::nullopt;
    }
    int low = 1;
    int high = 0;
    for (int p : piles) {
        assert(p > 0);
        high = std::max(high, p);
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        long long needed = 0;
        for (int p : piles) {
            needed += (p - 1) / mid + 1;
        }
        if (needed <= hours) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    assert(speed({3, 6, 7, 11}, 8) == 4);
    assert(!speed({3, 6}, 1));
    assert(speed({}, 0) == 0);
    assert(speed({9}, 1) == 9);
    std::cout << "checks passed\n";
    return 0;
}
