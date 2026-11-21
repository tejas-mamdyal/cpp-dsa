/*
 1<=k<=n; integer threshold; invalid k returns 0 counted windows.

IDEA AND STATE: Maintain a sum and test sum>=k*threshold in long long.

TRACE: 2,2,2,2 with k 2, threshold 2 has 3 qualifying windows.

The first pair sums to4,meeting2*2;each exchange preserves4,so all three windows qualify.

Multiplying by a positive k preserves the comparison and avoids rounding.

O(n) time, O(1) space.

Widen before multiplying; division truncation is not an average comparison.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int averageCount(const std::vector<int>& a, int k, int threshold) {
    if (k < 1 || k > static_cast<int>(a.size())) {
        return 0;
    }
    long long sum = 0;
    int count = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        sum += a[right];
        if (right >= k) {
            sum -= a[right - k];
        }
        if (right + 1 >= k && sum >= 1LL * k * threshold) {
            ++count;
        }
    }
    return count;
}

int main() {
    assert(averageCount({2, 2, 2, 2}, 2, 2) == 3);
    assert(averageCount({-1, -2, -3}, 2, -1) == 0);
    assert(averageCount({}, 1, 0) == 0);
    assert(averageCount({1}, 0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
