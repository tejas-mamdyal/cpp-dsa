/*
COUNT BOUNDED NONNEGATIVE KEYS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values0..100. IDEA AND STATE: Store a
frequency for every permitted value0..100, then emit the counts in ascending order. TRACE:
3,0,3,1 ->0,1,3,3. CORRECTNESS: Each input increments one counter and reconstruction emits
exactly those multiplicities. COST: O(n+R) time,O(R) space for R=101. PITFALL: A huge key
range can make counting impractical even for few elements. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sortValues(std::vector<int>& a) {
    int counts[101] = {};
    for (int value : a) {
        assert(value >= 0 && value <= 100);
        ++counts[value];
    }
    std::size_t write = 0;
    for (int value = 0; value <= 100; ++value) {
        for (int k = 0; k < counts[value]; ++k) {
            a[write++] = value;
        }
    }
}

int main() {
    for (std::vector<int> values : std::vector<std::vector<int>>{
             {}, {1}, {3, 1, 2, 1, 0}, {0, 0, 0}, {1, 2, 3, 4}, {4, 3, 2, 1}}) {
        auto expected = values;
        std::sort(expected.begin(), expected.end());
        sortValues(values);
        assert(values == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
