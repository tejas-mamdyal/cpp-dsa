/*
LSD RADIX SORT NEEDS STABLE DIGIT PASSES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values0..100. IDEA AND STATE: Sort
nonnegative ints0..9999 by units,tens,hundreds,thousands using stable counting passes. TRACE:
21,12,11:units11,21,12; then tens11,12,21. CORRECTNESS: After each stable pass all processed
lower digits are correctly ordered within the new higher-digit groups. COST: O(d*(n+10))
time,O(n+10) extra space for d decimal digits. PITFALL: Negative numbers require another
design; the stated upper bound also prevents exponent overflow. PRACTICE: Change the example,
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
    if (a.empty()) {
        return;
    }
    int maximum = *std::max_element(a.begin(), a.end());
    assert(maximum <= 9999);
    std::vector<int> out(a.size());
    for (int exponent = 1; maximum / exponent > 0; exponent *= 10) {
        int count[10] = {};
        for (int value : a) {
            assert(value >= 0);
            ++count[(value / exponent) % 10];
        }
        for (int digit = 1; digit < 10; ++digit) {
            count[digit] += count[digit - 1];
        }
        for (std::size_t i = a.size(); i > 0; --i) {
            int value = a[i - 1];
            int digit = (value / exponent) % 10;
            out[--count[digit]] = value;
        }
        a.swap(out);
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
