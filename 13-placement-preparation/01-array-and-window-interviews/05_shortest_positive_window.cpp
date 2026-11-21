/*
 Strictly positive elements and target;0 denotes no nonempty solution. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

The current window has positive elements; left advances only while target
is met.

4,3 is a length 2 window reaching 7.

Removing a positive left value decreases sum; every minimal valid ending window
is considered.

O(n) time, O(1) auxiliary storage.

For signed arrays use prefix/deque reasoning instead.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

int shortest(const std::vector<int>& a, int target) {
    std::size_t left = 0;
    int sum = 0;
    int best = static_cast<int>(a.size()) + 1;
    for (std::size_t right = 0; right < a.size(); ++right) {
        sum += a[right];
        while (sum >= target) {
            best = std::min(best, static_cast<int>(right - left + 1));
            sum -= a[left++];
        }
    }
    return best > static_cast<int>(a.size()) ? 0 : best;
}

int main() {
    assert(shortest({2, 3, 1, 2, 4, 3}, 7) == 2);
    assert(shortest({1, 1}, 3) == 0);
    assert(shortest({}, 1) == 0);
    std::cout << "checks passed\n";
    return 0;
}
