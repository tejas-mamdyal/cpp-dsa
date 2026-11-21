/*
REVERSE THE ORDER ASSUMPTIONS CONSISTENTLY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Vector sorted nonincreasingly; return any match index or-1. IDEA AND STATE: Larger
values lie left, so a[middle]<key discards the right side. TRACE: 9,7,4,1 target7 ->index1.
CORRECTNESS: The comparator order determines which half is impossible. COST: O(log(n+1))
time,O(1) space. PITFALL: An ascending search on descending data has the wrong invariant.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int descending(const std::vector<int>& a, int key) {
    int l = 0;
    int r = static_cast<int>(a.size()) - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == key) {
            return m;
        }
        if (a[m] < key) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

int main() {
    assert(descending({9, 7, 4, 1}, 7) == 1);
    assert(descending({}, 2) == -1);
    assert(descending({3, 3}, 3) >= 0);
    assert(descending({9, 7, 4, 1}, 2) == -1);
    std::cout << "checks passed\n";
    return 0;
}
