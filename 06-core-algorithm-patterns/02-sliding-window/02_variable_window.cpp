/*
 Nonnegative values, target>0; return shortest length with sum>=target, or absence.

IDEA AND STATE: Expand right, then remove left values while the target remains met.

TRACE: 2,3,1,2,4,3 target 7 ->length 2.

After reaching the final3,sum reaches9;remove2 then4 while recording valid lengths3 then2,so
the best is2.

Nonnegativity makes removing a left value never increase the sum; all potentially
shorter valid endings are tested.

O(n) time, O(1) space.

Negative values invalidate this shrinking argument; see the counterexample lesson.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> minLength(const std::vector<int>& a, long long target) {
    assert(target > 0);
    int left = 0;
    int best = static_cast<int>(a.size()) + 1;
    long long sum = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        assert(a[right] >= 0);
        sum += a[right];
        while (left <= right && sum >= target) {
            best = std::min(best, right - left + 1);
            sum -= a[left];
            ++left;
        }
    }
    if (best > static_cast<int>(a.size())) {
        return std::nullopt;
    }
    return best;
}

int main() {
    assert(minLength({2, 3, 1, 2, 4, 3}, 7) == 2);
    assert(minLength({0, 0, 5}, 5) == 1);
    assert(!minLength({}, 1));
    assert(!minLength({1, 2}, 4));
    std::cout << "checks passed\n";
    return 0;
}
