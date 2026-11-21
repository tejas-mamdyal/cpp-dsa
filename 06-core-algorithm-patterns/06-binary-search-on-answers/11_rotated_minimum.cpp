/*
 Rotation of strictly increasing array; minimum value or absence.

IDEA AND STATE: mid>right puts the minimum after mid; otherwise mid remains a candidate.

TRACE: 3,4,5,1,2 ->1.

Comparing midpoint5 with right2 moves low beyond the pivot;remaining comparisons retain1 as
the minimum.

The rotated increasing structure identifies which side contains the unique
minimum; keeping mid handles its own minimum case.

O(log n) time, O(1) space.

high=mid-1 could discard the minimum.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

std::optional<int> rotatedMin(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    int low = 0;
    int high = static_cast<int>(a.size()) - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (a[mid] > a[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return a[low];
}

int main() {
    assert(rotatedMin({3, 4, 5, 1, 2}) == 1);
    assert(rotatedMin({1, 2}) == 1);
    assert(!rotatedMin({}));
    std::cout << "checks passed\n";
    return 0;
}
