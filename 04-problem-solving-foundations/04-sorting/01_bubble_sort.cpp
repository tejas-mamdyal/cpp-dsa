/*
BUBBLE SORT WITH A SHRINKING UNSORTED SUFFIX PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: Swap adjacent inversions; each pass fixes the largest remaining value. Stop after a
pass without swaps. TRACE: 3,1,2 ->1,2,3 on the first pass. CORRECTNESS: Every comparison
pushes a larger neighbor rightward; the last active position is final. COST: O(n^2) worst,
O(n) already-sorted time; O(1) extra space; stable. PITFALL: The no-swap flag must reset on
each pass. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sortValues(std::vector<int>& a) {
    for (std::size_t end = a.size(); end > 1; --end) {
        bool changed = false;
        for (std::size_t i = 1; i < end; ++i) {
            if (a[i - 1] > a[i]) {
                std::swap(a[i - 1], a[i]);
                changed = true;
            }
        }
        if (!changed) {
            break;
        }
    }
}

int main() {
    for (std::vector<int> values : std::vector<std::vector<int>>{
             {}, {1}, {3, -1, 2, -1, 0}, {0, 0, 0}, {-2, 0, 3, 4}, {4, 3, 0, -2}}) {
        auto expected = values;
        std::sort(expected.begin(), expected.end());
        sortValues(values);
        assert(values == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
