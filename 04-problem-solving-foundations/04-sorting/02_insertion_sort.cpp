/*
INSERTION SORT GROWS A SORTED PREFIX PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: Save the next value, shift strictly greater predecessors, then insert it. TRACE:
1,4,2 ->save2,shift4 ->1,2,4. CORRECTNESS: The prefix is sorted before insertion; shifting
opens its unique stable insertion location. COST: O(n^2) worst,O(n) best time; O(1) extra
space; stable. PITFALL: Save the value before shifts overwrite its old slot. PRACTICE: Change
the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sortValues(std::vector<int>& a) {
    for (std::size_t i = 1; i < a.size(); ++i) {
        int value = a[i];
        std::size_t position = i;
        while (position > 0 && a[position - 1] > value) {
            a[position] = a[position - 1];
            --position;
        }
        a[position] = value;
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
