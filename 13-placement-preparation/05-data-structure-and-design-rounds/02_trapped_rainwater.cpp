/*
 Nonnegative heights.

leftMax/rightMax are established boundaries outside the remaining
interval.

The standard profile traps 6 total units.

The smaller established boundary already limits its side regardless of any
farther larger boundary.

O(n) time, O(1) work.

Water depends on the smaller of both side maxima, not just a local dip.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int water(const std::vector<int>& a) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;
    while (left <= right) {
        if (leftMax <= rightMax) {
            leftMax = std::max(leftMax, a[left]);
            total += leftMax - a[left++];
        } else {
            rightMax = std::max(rightMax, a[right]);
            total += rightMax - a[right--];
        }
    }
    return total;
}

int main() {
    assert(water({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) == 6);
    assert(water({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
