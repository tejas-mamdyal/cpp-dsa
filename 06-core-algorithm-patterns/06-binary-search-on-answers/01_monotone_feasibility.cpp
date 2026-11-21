/*
 Boolean table must have only false then true; empty/all-false has no answer.

IDEA AND STATE: Keep a half-open unresolved index interval; true discards itself and the right
half from further search.

TRACE: false, false, true, true ->2.

With bounds0,4,mid2 is true so high becomes2;mid1 is false so low becomes2;return2.

The first true remains in the candidate interval or at its right sentinel; each
step halves its width.

O(log n) search, O(1) auxiliary; the teaching assertion validates the table in O(n).

A true, false, true table has no monotone boundary; binary search on it is unjustified.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

std::optional<int> firstTrue(const std::vector<bool>& a) {
    bool seen = false;
    for (bool value : a) {
        assert(!seen || value);
        seen = seen || value;
    }
    int low = 0;
    int high = static_cast<int>(a.size());
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (a[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    if (low == static_cast<int>(a.size())) {
        return std::nullopt;
    }
    return low;
}

int main() {
    assert(firstTrue({false, false, true, true}) == 2);
    assert(firstTrue({true}) == 0);
    assert(!firstTrue({false, false}));
    assert(!firstTrue({}));
    std::cout << "checks passed\n";
    return 0;
}
