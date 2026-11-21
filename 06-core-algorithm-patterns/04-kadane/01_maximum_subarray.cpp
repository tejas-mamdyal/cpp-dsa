/*
 Signed values; empty input has no nonempty answer.

IDEA AND STATE: Either start here or extend the best previous suffix.

TRACE: -2,1,-3,4,-1,2,1,-5,4 ->6.

At4,the negative carried suffix is discarded;ending sums then grow4,3,5,6 before dropping,so
best stays6.

Every subarray ending here has exactly those two possibilities; maximize over
endpoints.

O(n) time, O(1) auxiliary space.

Starting best at zero invents an empty answer for all-negative data.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<long long> maximum(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    long long ending = a[0];
    long long best = ending;
    for (std::size_t i = 1; i < a.size(); ++i) {
        ending = std::max(1LL * a[i], ending + a[i]);
        best = std::max(best, ending);
    }
    return best;
}

int main() {
    assert(maximum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
    assert(maximum({-8, -2, -5}) == -2);
    assert(!maximum({}));
    std::cout << "checks passed\n";
    return 0;
}
