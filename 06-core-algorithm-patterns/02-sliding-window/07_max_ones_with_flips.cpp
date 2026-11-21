/*
 Binary array; k>=0 zero-to-one flips available.

IDEA AND STATE: A window is feasible exactly when its zero count<=k.

TRACE: 1,0,1,0,1 with k 1 ->3.

The first three values use one zero;the next zero forces removing through the earlier zero,so
best length stays3.

Shrinking removes excess zeros and leaves the longest feasible suffix.

O(n) time, O(1) space.

Count zeros, not all characters different from an arbitrary current candidate.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int longestOnes(const std::vector<int>& a, int k) {
    assert(k >= 0);
    int left = 0;
    int zeros = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        assert(a[right] == 0 || a[right] == 1);
        if (a[right] == 0) {
            ++zeros;
        }
        while (zeros > k) {
            if (a[left] == 0) {
                --zeros;
            }
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    assert(longestOnes({1, 0, 1, 0, 1}, 1) == 3);
    assert(longestOnes({0, 0}, 0) == 0);
    assert(longestOnes({}, 2) == 0);
    assert(longestOnes({0, 0}, 2) == 2);
    std::cout << "checks passed\n";
    return 0;
}
