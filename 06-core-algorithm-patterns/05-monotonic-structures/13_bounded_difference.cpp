/*
 Nonnegative limit; longest range with max-min<=limit.

IDEA AND STATE: Maintain increasing minima and decreasing maxima; shrink while their difference
is too large.

TRACE: 8,2,4,7 limit 4 ->2.

For8,2,the spread6 forces removing8;2,4 then fits,but adding7 forces removing2,so best
length2.

Removing a left endpoint cannot increase spread; each right endpoint retains its
longest feasible suffix.

O(n) time, O(n) worst-case auxiliary space.

Compute the difference in long long.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
#include <algorithm>

int longestSpread(const std::vector<int>& a, long long limit) {
    assert(limit >= 0);
    std::deque<int> low;
    std::deque<int> high;
    int left = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        while (!low.empty() && a[low.back()] >= a[right]) {
            low.pop_back();
        }
        while (!high.empty() && a[high.back()] <= a[right]) {
            high.pop_back();
        }
        low.push_back(right);
        high.push_back(right);
        while (1LL * a[high.front()] - a[low.front()] > limit) {
            if (low.front() == left) {
                low.pop_front();
            }
            if (high.front() == left) {
                high.pop_front();
            }
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    assert(longestSpread({8, 2, 4, 7}, 4) == 2);
    assert(longestSpread({2, 2, 2}, 0) == 3);
    assert(longestSpread({}, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
