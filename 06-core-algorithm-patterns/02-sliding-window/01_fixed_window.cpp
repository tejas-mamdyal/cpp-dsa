/*
 1<=k<=n; invalid sizes return absence, including empty input. Signed values are
allowed.

IDEA AND STATE: Form the first sum, then add the entering value and remove the leaving value.

TRACE: -3,-2,-5 with k 2 ->-5.

First window -3,-2 sums to -5;replace -3 with -5 to get -7,so -5 stays best.

Each update preserves exactly k consecutive values and every eligible endpoint is
visited.

O(n) time, O(1) space.

Do not initialize best to 0 when all sums may be negative.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<long long> maxFixed(const std::vector<int>& a, int k) {
    if (k < 1 || k > static_cast<int>(a.size())) {
        return std::nullopt;
    }
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += a[i];
    }
    long long best = sum;
    for (int right = k; right < static_cast<int>(a.size()); ++right) {
        sum += a[right];
        sum -= a[right - k];
        best = std::max(best, sum);
    }
    return best;
}

int main() {
    assert(maxFixed({1, 4, 2, 10, 2, 3, 1, 0, 20}, 4) == 24);
    assert(maxFixed({-3, -2, -5}, 2) == -5);
    assert(!maxFixed({}, 1));
    assert(!maxFixed({1}, 0));
    assert(maxFixed({7}, 1) == 7);
    std::cout << "checks passed\n";
    return 0;
}
