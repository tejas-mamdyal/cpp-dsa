/*
 Nonnegative values, budget>=0; empty answer length 0 is permitted.

IDEA AND STATE: Shrink only while sum exceeds budget, then record the longest valid suffix
ending here.

TRACE: 1,2,1,1 budget 3 ->length 2.

After1,2 the sum is3;the next1 forces removing the first1;the last1 forces removing2,so
maximum length remains2.

Any discarded left endpoint remains too expensive for this or later right
endpoints until removed.

O(n) time, O(1) space.

The longest valid window keeps as much of the left prefix as possible.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int longestBudget(const std::vector<int>& a, long long budget) {
    assert(budget >= 0);
    long long sum = 0;
    int left = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        assert(a[right] >= 0);
        sum += a[right];
        while (sum > budget) {
            sum -= a[left];
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    assert(longestBudget({1, 2, 1, 1}, 3) == 2);
    assert(longestBudget({0, 0, 0}, 0) == 3);
    assert(longestBudget({}, 3) == 0);
    assert(longestBudget({5}, 2) == 0);
    std::cout << "checks passed\n";
    return 0;
}
