/*
FIRST POSITION GREATER THAN A KEY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Sorted vector; return first strictly greater index, or size. IDEA AND STATE: Move
past values<=key. TRACE: 1,2,2,5 key2 ->3. CORRECTNESS: The rejected prefix is entirely<=key;
remaining interval contains the first greater candidate. COST: O(log(n+1)) time,O(1) space.
PITFALL: Changing <= to < instead computes lower_bound. PRACTICE: Change the example, predict
each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::size_t upper(const std::vector<int>& a, int key) {
    std::size_t left = 0;
    std::size_t right = a.size();
    while (left < right) {
        std::size_t middle = left + (right - left) / 2;
        if (a[middle] <= key) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

int main() {
    std::vector<int> a = {1, 2, 2, 5};
    for (int key = -1; key <= 7; ++key) {
        assert(upper(a, key)
               == static_cast<std::size_t>(std::upper_bound(a.begin(), a.end(), key) - a.begin()));
    }
    assert(upper({}, 4) == 0);
    std::cout << "checks passed\n";
    return 0;
}
