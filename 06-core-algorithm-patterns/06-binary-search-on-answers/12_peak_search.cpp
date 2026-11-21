/*
 Adjacent values unequal; outside endpoints treated as negative infinity; return any
strict peak index or absence.

IDEA AND STATE: Compare mid to mid+1; keep the rising side or include mid on a falling side.

TRACE: 1,3,2 ->index 1.

At middle3,the next value2 is lower,so retain the left half including3;it becomes the returned
peak.

An uphill direction must eventually reach a descent or an endpoint peak; the
retained interval always contains a peak.

O(log n) time, O(1) space.

A peak need not be the global maximum; plateaus violate this contract.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

std::optional<int> peak(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    int low = 0;
    int high = static_cast<int>(a.size()) - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (a[mid] < a[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    assert(peak({1, 3, 2}) == 1);
    assert(peak({1, 2, 3}) == 2);
    assert(peak({5}) == 0);
    assert(!peak({}));
    std::cout << "checks passed\n";
    return 0;
}
