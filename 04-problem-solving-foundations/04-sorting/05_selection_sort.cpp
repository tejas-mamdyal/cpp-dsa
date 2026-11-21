/*
SELECTION SORT FIXES ONE MINIMUM AT A TIME PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: Find the smallest suffix value then swap it into the next position. TRACE: 3,1,2
->1,3,2 ->1,2,3. CORRECTNESS: After each pass the prefix contains the smallest values in
sorted order. COST: Theta(n^2) comparisons,O(n) swaps,O(1) space; generally unstable. PITFALL:
One distant swap can reverse equal-key record order. PRACTICE: Change the example, predict
each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sortValues(std::vector<int>& a) {
    for (std::size_t i = 0; i < a.size(); ++i) {
        std::size_t best = i;
        for (std::size_t j = i + 1; j < a.size(); ++j) {
            if (a[j] < a[best]) {
                best = j;
            }
        }
        std::swap(a[i], a[best]);
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
