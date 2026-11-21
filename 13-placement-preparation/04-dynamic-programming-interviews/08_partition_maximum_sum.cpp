/*
 k>=1; every element must belong to a block of at most k elements. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

best[end] covers the whole prefix; the final block is replaced by its
maximum.

Block 1,15,7 becomes 15,15,15.

Every legal partition has a final block length 1..k and an optimal earlier
prefix.

O(n*k) time, O(n) storage.

For signed input, zero-initialized nonempty optima would incorrectly permit skipping
coverage.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

int partition(const std::vector<int>& a, int k) {
    std::vector<int> best(a.size() + 1);
    for (int end = 1; end <= static_cast<int>(a.size()); ++end) {
        best[end] = std::numeric_limits<int>::min();
        int maximum = std::numeric_limits<int>::min();
        for (int length = 1; length <= k && length <= end; ++length) {
            maximum = std::max(maximum, a[end - length]);
            best[end] = std::max(best[end], best[end - length] + length * maximum);
        }
    }
    return best.back();
}

int main() {
    assert(partition({1, 15, 7, 9, 2, 5, 10}, 3) == 84);
    assert(partition({-2, -3}, 2) == -4);
    assert(partition({}, 2) == 0);
    std::cout << "checks passed\n";
    return 0;
}
