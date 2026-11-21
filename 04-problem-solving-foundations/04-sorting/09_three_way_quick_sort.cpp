/*
THREE-WAY PARTITION HANDLES MANY EQUAL KEYS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: Maintain less-than, equal and unknown regions plus a greater suffix. TRACE:
2,1,2,3,2 ->less1,equal2,2,2,greater3. CORRECTNESS: Each step moves a value to its correct
pivot region; only less/greater regions need recursion. COST: O(n^2) worst,O(n log n) typical;
all-equal input O(n); O(n) worst stack. PITFALL: After swapping an unknown with the right
boundary, inspect the incoming value before advancing. PRACTICE: Change the example, predict
each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void quick3(std::vector<int>& a, int left, int right) {
    if (right - left < 2) {
        return;
    }
    int pivot = a[left];
    int less = left;
    int i = left;
    int greater = right;
    while (i < greater) {
        if (a[i] < pivot) {
            std::swap(a[i], a[less]);
            ++i;
            ++less;
        } else if (a[i] > pivot) {
            std::swap(a[i], a[--greater]);
        } else {
            ++i;
        }
    }
    quick3(a, left, less);
    quick3(a, greater, right);
}

void sortValues(std::vector<int>& a) {
    quick3(a, 0, static_cast<int>(a.size()));
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
