/*
 Sorted inputs;1<=k<=combined length.

Cuts i, j contain k elements total; both left maxima must not exceed
opposite right minima.

For k 4, cut 2+2 gives left max 4 and right min 5.

If a-left exceeds b-right, all larger a-cuts are invalid; the symmetric case
requires a larger cut.

O(log(min(n, m)+1)) time, O(1) work plus at most one swap-call.

Ranks here are 1-based; empty total input has no legal rank.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

int kth(const std::vector<int>& a, const std::vector<int>& b, int k) {
    if (a.size() > b.size()) {
        return kth(b, a, k);
    }
    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());
    int low = std::max(0, k - m);
    int high = std::min(k, n);
    while (low <= high) {
        int i = (low + high) / 2;
        int j = k - i;
        int al = i ? a[i - 1] : std::numeric_limits<int>::min();
        int ar = i < n ? a[i] : std::numeric_limits<int>::max();
        int bl = j ? b[j - 1] : std::numeric_limits<int>::min();
        int br = j < m ? b[j] : std::numeric_limits<int>::max();
        if (al <= br && bl <= ar) {
            return std::max(al, bl);
        }
        if (al > br) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    throw std::invalid_argument("rank");
}

int main() {
    assert(kth({1, 3, 5}, {2, 4, 6}, 4) == 4);
    assert(kth({}, {7}, 1) == 7);
    assert(kth({2, 2}, {2}, 2) == 2);
    std::cout << "checks passed\n";
    return 0;
}
