/*
DUPLICATE RANGE VIA TWO BOUNDARIES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Sorted vector; report count without scanning every duplicate. IDEA AND STATE: One
boundary finds first>=key and the other first>key. TRACE: 1,2,2,2,8 target2 gives[1,4),count3.
CORRECTNESS: Exactly the equal values lie between the two partition boundaries. COST:
O(log(n+1)) time,O(1) space. PITFALL: Counting by scanning after one found match can degrade
to linear. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::size_t boundary(const std::vector<int>& a, int key, bool strict) {
    std::size_t l = 0;
    std::size_t r = a.size();
    while (l < r) {
        std::size_t m = l + (r - l) / 2;
        bool before = a[m] < key;
        if (strict) {
            before = a[m] <= key;
        }
        if (before) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

std::size_t count(const std::vector<int>& a, int key) {
    return boundary(a, key, true) - boundary(a, key, false);
}

int main() {
    assert(count({1, 2, 2, 2, 8}, 2) == 3);
    assert(count({}, 2) == 0);
    assert(count({2, 2}, 3) == 0);
    for (int key = 0; key <= 9; ++key) {
        std::vector<int> a = {1, 2, 2, 2, 8};
        assert(count(a, key) == static_cast<std::size_t>(std::count(a.begin(), a.end(), key)));
    }
    std::cout << "checks passed\n";
    return 0;
}
