/*
KERNIGHAN COUNT VERSUS A BIT-BY-BIT ORACLE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Unsigned fixed-width values. IDEA AND STATE: value&(value-1) removes the lowest set
bit. TRACE: 12 ->8 ->0, two set bits. CORRECTNESS: Every iteration removes exactly one1 and
terminates when none remain. COST: O(popcount) operations,O(1) space. PITFALL: Do not subtract
from a signed minimum; zero must skip the loop. PRACTICE: Change the example, predict each
state update and add an empty/boundary case. No input unless explicitly stated. Assertions are
the teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>

int countBits(unsigned int value) {
    int count = 0;
    while (value != 0U) {
        value &= value - 1U;
        ++count;
    }
    return count;
}

int slowCount(unsigned int value) {
    int count = 0;
    while (value != 0U) {
        count += static_cast<int>(value % 2U);
        value /= 2U;
    }
    return count;
}

int main() {
    for (unsigned int value = 0; value < 1024U; ++value) {
        assert(countBits(value) == slowCount(value));
    }
    assert(countBits(0U) == 0);
    assert(countBits(255U) == 8);
    std::cout << "checks passed\n";
    return 0;
}
