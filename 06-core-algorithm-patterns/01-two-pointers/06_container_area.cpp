/*
 Nonnegative heights; choose two indices to maximize width*minimum height.

IDEA AND STATE: A shorter wall cannot improve by keeping it and reducing width.

TRACE: 1,8,6,2,5,4,8,3,7 ->49.

Initial walls1 and7 give area8;moving the shorter left wall reaches8 and7,width7,area49.

Any better pair must discard a limiting shorter endpoint; the retained best
records every eliminated candidate bound.

O(n) time, O(1) space.

This is container area, not the sum of trapped rainwater.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long area(const std::vector<int>& h) {
    int l = 0;
    int r = static_cast<int>(h.size()) - 1;
    long long best = 0;
    while (l < r) {
        best = std::max(best, 1LL * (r - l) * std::min(h[l], h[r]));
        if (h[l] <= h[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return best;
}

long long bruteArea(const std::vector<int>& h) {
    long long best = 0;
    for (int i = 0; i < static_cast<int>(h.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(h.size()); ++j) {
            best = std::max(best, 1LL * (j - i) * std::min(h[i], h[j]));
        }
    }
    return best;
}

int main() {
    assert(area({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
    for (std::vector<int> a :
         std::vector<std::vector<int>>{{}, {2}, {0, 0}, {3, 1, 4, 2}, {5, 5}}) {
        assert(area(a) == bruteArea(a));
    }
    std::cout << "checks passed\n";
    return 0;
}
