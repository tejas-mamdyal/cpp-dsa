/*
 Rotation of a strictly increasing array; return target index or -1.

IDEA AND STATE: Identify the sorted half and ask whether its closed value range contains
target.

TRACE: 4,5,6,7,0,1,2 searching 0 ->4.

Midpoint7 identifies the sorted left half;target0 lies outside it,so search keeps the right
half and finds index4.

The sorted half either contains the target or can be safely discarded; the other
half stays eligible.

O(log n) time, O(1) space.

This proof uses distinct values; duplicates can hide the sorted side.
*/
#include <iostream>
#include <cassert>
#include <vector>

int search(const std::vector<int>& a, int target) {
    int low = 0;
    int high = static_cast<int>(a.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) {
            return mid;
        }
        if (a[low] <= a[mid]) {
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
    return -1;
}

int main() {
    assert(search({4, 5, 6, 7, 0, 1, 2}, 0) == 4);
    assert(search({1}, 2) == -1);
    assert(search({}, 1) == -1);
    std::cout << "checks passed\n";
    return 0;
}
