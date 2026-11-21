/*
 Nonnegative heights; return total trapped unit-width water.

IDEA AND STATE: Track maximum seen from each side; the smaller boundary fixes the currently
processed side.

TRACE: 0,1,0,2,1,0,1,3,2,1,2,1 ->6.

In3,0,3,left maximum reaches3;the middle height0 contributes3,and the two walls contribute0.

The opposite boundary is already high enough for the smaller side, so no future
interior height can increase its water level beyond its known maximum.

O(n) time, O(1) space.

Add water only after updating that side maximum; negative heights violate the model.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long trapped(const std::vector<int>& h) {
    int l = 0;
    int r = static_cast<int>(h.size()) - 1;
    int leftMax = 0;
    int rightMax = 0;
    long long water = 0;
    while (l <= r) {
        if (h[l] <= h[r]) {
            leftMax = std::max(leftMax, h[l]);
            water += leftMax - h[l];
            ++l;
        } else {
            rightMax = std::max(rightMax, h[r]);
            water += rightMax - h[r];
            --r;
        }
    }
    return water;
}

int main() {
    assert(trapped({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) == 6);
    assert(trapped({}) == 0);
    assert(trapped({3}) == 0);
    assert(trapped({3, 0, 3}) == 3);
    assert(trapped({1, 2, 3}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
