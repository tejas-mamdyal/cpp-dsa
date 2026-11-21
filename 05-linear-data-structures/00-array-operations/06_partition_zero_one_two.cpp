/*
THREE-WAY PARTITION OF A RESTRICTED ALPHABET PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Values only0,1,2. IDEA AND STATE: Maintain zeros prefix, ones region, unknown
interval and twos suffix. TRACE: 2,0,1,2,0 ->0,0,1,2,2. CORRECTNESS: Each action moves a value
to a final category and shrinks unknown positions. COST: O(n) time,O(1) space; not stable.
PITFALL: Do not advance after swapping an unknown right-side value into the current position.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void colors(std::vector<int>& a) {
    std::size_t zero = 0;
    std::size_t i = 0;
    std::size_t two = a.size();
    while (i < two) {
        if (a[i] == 0) {
            std::swap(a[i], a[zero]);
            ++i;
            ++zero;
        } else if (a[i] == 2) {
            --two;
            std::swap(a[i], a[two]);
        } else {
            assert(a[i] == 1);
            ++i;
        }
    }
}

int main() {
    for (std::vector<int> a :
         std::vector<std::vector<int>>{{}, {2, 0, 1, 2, 0}, {1, 1}, {2, 2}, {0}}) {
        auto expected = a;
        std::sort(expected.begin(), expected.end());
        colors(a);
        assert(a == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
