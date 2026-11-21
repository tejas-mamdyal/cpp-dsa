/*
BINARY INSERTION REDUCES COMPARISONS NOT SHIFTS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: Find an upper insertion boundary in the sorted prefix, then shift the suffix.
TRACE: 1,4,4 inserting another4 uses the position after existing4 values. CORRECTNESS: The
binary boundary is correct for the sorted prefix; shifting preserves the remaining order.
COST: O(n log n) comparisons but O(n^2) worst moves/time; O(1) space; stable. PITFALL: A
logarithmic position search does not make linear shifting disappear. PRACTICE: Change the
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
    for (std::size_t i = 1; i < a.size(); ++i) {
        int value = a[i];
        std::size_t l = 0;
        std::size_t r = i;
        while (l < r) {
            std::size_t m = l + (r - l) / 2;
            if (a[m] <= value) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        for (std::size_t j = i; j > l; --j) {
            a[j] = a[j - 1];
        }
        a[l] = value;
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
