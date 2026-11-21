/*
BIDIRECTIONAL BUBBLE PASSES PREREQUISITES: Phases1/2 C++ and STL, Phase3 complexity/recursion,

filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: Sweep right to fix a maximum, then left to fix a minimum; shrink both boundaries.
TRACE: 3,2,1 ->2,1,3 ->1,2,3. CORRECTNESS: Each sweep settles an endpoint without disturbing
already settled positions. COST: O(n^2) worst,O(n) best time; O(1) space; stable with strict
swaps. PITFALL: Guard empty input and unsigned decrement loops carefully. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sortValues(std::vector<int>& a) {
    if (a.size() < 2) {
        return;
    }
    std::size_t left = 0;
    std::size_t right = a.size() - 1;
    while (left < right) {
        bool changed = false;
        for (std::size_t i = left; i < right; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                changed = true;
            }
        }
        --right;
        for (std::size_t i = right; i > left; --i) {
            if (a[i - 1] > a[i]) {
                std::swap(a[i - 1], a[i]);
                changed = true;
            }
        }
        ++left;
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
