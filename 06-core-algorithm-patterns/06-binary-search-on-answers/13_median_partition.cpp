/*
 Sorted integer arrays; combined size>0 or absence; duplicates allowed.

IDEA AND STATE: Search a cut in the shorter array; derive the other cut and compare cross
boundaries.

TRACE: 1,3 and 2 ->2;1,2 and 3,4 ->2.5.

For1,3 and2,a cut leaves1,2 on the left and3 on the right;left maximum2 is the odd median.

When both left maxima are <= opposite right minima, the balanced left/right halves
define the median.

O(log(min(n, m)+1)) time, O(1) auxiliary.

Use long long sentinels and convert before averaging; empty input is not a numeric
zero median.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <limits>
#include <utility>

std::optional<double> median(const std::vector<int>& first, const std::vector<int>& second) {
    const auto* a = &first;
    const auto* b = &second;
    if (a->size() > b->size()) {
        std::swap(a, b);
    }
    int n = static_cast<int>(a->size());
    int m = static_cast<int>(b->size());
    if (n + m == 0) {
        return std::nullopt;
    }
    int low = 0;
    int high = n;
    while (low <= high) {
        int i = low + (high - low) / 2;
        int j = (n + m + 1) / 2 - i;
        long long al = i == 0 ? std::numeric_limits<long long>::lowest() : (*a)[i - 1];
        long long ar = i == n ? std::numeric_limits<long long>::max() : (*a)[i];
        long long bl = j == 0 ? std::numeric_limits<long long>::lowest() : (*b)[j - 1];
        long long br = j == m ? std::numeric_limits<long long>::max() : (*b)[j];
        if (al <= br && bl <= ar) {
            if ((n + m) % 2 == 1) {
                return static_cast<double>(std::max(al, bl));
            }
            return (static_cast<double>(std::max(al, bl)) + static_cast<double>(std::min(ar, br)))
                   / 2.0;
        }
        if (al > br) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return std::nullopt;
}

int main() {
    assert(median({1, 3}, {2}) == 2.0);
    assert(median({1, 2}, {3, 4}) == 2.5);
    assert(median({}, {7}) == 7.0);
    assert(!median({}, {}));
    std::cout << "checks passed\n";
    return 0;
}
