/*
 A leader is at least every value to its right; return leaders in original order.

IDEA AND STATE: Build suffix maximum values backward, then compare each value with the
following suffix maximum.

TRACE: 16,17,4,3,5,2 ->17,5,2.

Scan from2 backward:keep2,5,and17 as new suffix maxima,then reverse those kept values.

The suffix summary represents every right-side competitor, so one comparison
suffices per index.

O(n) time, O(n) suffix storage plus output.

The non-strict definition deliberately includes both entries of[2,2].
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> leaders(const std::vector<int>& a) {
    if (a.empty()) {
        return {};
    }
    std::vector<int> suffix(a.size());
    suffix.back() = a.back();
    for (std::size_t i = a.size() - 1; i > 0; --i) {
        suffix[i - 1] = std::max(a[i - 1], suffix[i]);
    }
    std::vector<int> result;
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (i + 1 == a.size() || a[i] >= suffix[i + 1]) {
            result.push_back(a[i]);
        }
    }
    return result;
}

int main() {
    assert((leaders({16, 17, 4, 3, 5, 2}) == std::vector<int>{17, 5, 2}));
    assert((leaders({2, 2}) == std::vector<int>{2, 2}));
    assert(leaders({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
