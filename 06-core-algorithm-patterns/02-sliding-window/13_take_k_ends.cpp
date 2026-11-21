/*
 Choose exactly k values from either end; k 0 valid, invalid sizes absent. Signed values
allowed.

IDEA AND STATE: Start with the first k, then replace one prefix value at a time by one suffix
value.

TRACE: 1,2,3,4,5,6,1 with k 3 ->12.

Start with1+2+3=6;exchange a left pick for the rightmost1,then for6,then5;the final right-only
total is12.

Every legal choice is some prefix length plus suffix length totaling k; all k+1
splits are visited.

O(k) time, O(1) space.

This is not a nonnegative shrinking-window assumption and works for signed values.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<long long> takeEnds(const std::vector<int>& a, int k) {
    if (k < 0 || k > static_cast<int>(a.size())) {
        return std::nullopt;
    }
    long long current = 0;
    for (int i = 0; i < k; ++i) {
        current += a[i];
    }
    long long best = current;
    for (int suffix = 1; suffix <= k; ++suffix) {
        current -= a[k - suffix];
        current += a[a.size() - static_cast<std::size_t>(suffix)];
        best = std::max(best, current);
    }
    return best;
}

int main() {
    assert(takeEnds({1, 2, 3, 4, 5, 6, 1}, 3) == 12);
    assert(takeEnds({-3, -2, -5}, 1) == -3);
    assert(takeEnds({}, 0) == 0);
    assert(!takeEnds({1}, 2));
    std::cout << "checks passed\n";
    return 0;
}
