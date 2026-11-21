/*
 Positive weights; positive capacity; at most 2 per boat; oversize passenger makes answer
absent.

IDEA AND STATE: Sort; if lightest plus heaviest fits, pair them; otherwise send heaviest alone.

TRACE: 3,2,2,1 capacity 3 ->3 boats.

Weight3 cannot pair with1 under capacity3,so goes alone;then2 pairs with1,and the remaining2
goes alone.

If heaviest cannot pair with lightest, it cannot pair at all; if it can, an exchange
puts lightest with it without increasing boats.

O(n log n) time, O(n) copied input.

The proof relies on at most two people per boat.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> boats(std::vector<int> a, int capacity) {
    assert(capacity > 0);
    std::sort(a.begin(), a.end());
    if (!a.empty() && a.back() > capacity) {
        return std::nullopt;
    }
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    int count = 0;
    while (left <= right) {
        assert(a[left] > 0);
        if (left < right && 1LL * a[left] + a[right] <= capacity) {
            ++left;
        }
        --right;
        ++count;
    }
    return count;
}

int main() {
    assert(boats({3, 2, 2, 1}, 3) == 3);
    assert(!boats({4}, 3));
    assert(boats({}, 3) == 0);
    assert(boats({1, 1}, 2) == 1);
    std::cout << "checks passed\n";
    return 0;
}
