/*
 Demonstrate a deliberately invalid application, then compare with a correct bounded
brute-force result.

IDEA AND STATE: The tempting rule discards 5 before seeing-4, even though their full sum fits
the budget.

TRACE: [5,-4], budget 3: wrong shrink gives 1, correct longest length 2.

The wrong rule drops5 immediately and later sees only -4,length1;enumeration retains the full
sum1,length2.

Removing a positive left value before a later negative arrives can discard a
future valid start; the monotonicity proof is unavailable.

Demonstration O(n); oracle O(n^2), both O(1) extra space.

The function named wrongForSigned is a counterexample, not a general signed-array
solution.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int wrongForSigned(const std::vector<int>& a, long long limit) {
    long long sum = 0;
    int left = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        sum += a[right];
        while (left <= right && sum > limit) {
            sum -= a[left];
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int bruteLongest(const std::vector<int>& a, long long limit) {
    int best = 0;
    for (int l = 0; l < static_cast<int>(a.size()); ++l) {
        long long sum = 0;
        for (int r = l; r < static_cast<int>(a.size()); ++r) {
            sum += a[r];
            if (sum <= limit) {
                best = std::max(best, r - l + 1);
            }
        }
    }
    return best;
}

int main() {
    assert(wrongForSigned({5, -4}, 3) == 1);
    assert(bruteLongest({5, -4}, 3) == 2);
    assert(bruteLongest({}, 3) == 0);
    std::cout << "checks passed\n";
    return 0;
}
