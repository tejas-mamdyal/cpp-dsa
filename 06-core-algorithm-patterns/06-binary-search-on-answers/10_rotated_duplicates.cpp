/*
 Rotation of nondecreasing array; return target presence.

IDEA AND STATE: If low, mid, high are equal after failing equality to target, discard both
endpoints.

TRACE: 1,0,1,1,1 searching 0 ->true.

Equal boundary values1 hide the pivot;discard equal failed endpoints until the side
containing0 is exposed.

Equal failed endpoints cannot be target; otherwise sorted-half exclusion is valid
as before.

O(n) worst-case time, O(1) space.

Claiming logarithmic worst-case ignores arrays of repeated values.
*/
#include <iostream>
#include <cassert>
#include <vector>

bool contains(const std::vector<int>& a, int target) {
    int low = 0;
    int high = static_cast<int>(a.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) {
            return true;
        }
        if (a[low] == a[mid] && a[mid] == a[high]) {
            ++low;
            --high;
        } else if (a[low] <= a[mid]) {
            if (a[low] <= target && target < a[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (a[mid] < target && target <= a[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    assert(contains({1, 0, 1, 1, 1}, 0));
    assert(!contains({1, 1, 1}, 2));
    assert(!contains({}, 0));
    std::cout << "checks passed\n";
    return 0;
}
