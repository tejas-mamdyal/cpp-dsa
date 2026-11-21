/*
UNSIGNED BIT MASKS AND SAFE POSITIONS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Unsigned values and bit positions below numeric_limits<unsigned int>::digits. IDEA
AND STATE: One-bit masks select individual flags; AND/OR/XOR implement clear/set/toggle/test.
TRACE: 12 and10 ->AND8,OR14,XOR6;set bit0 ->13. CORRECTNESS: Each bit operation follows its
truth table independently. COST: O(1) fixed-width operations and storage. PITFALL: A shift by
the type width is invalid; unsigned complement flips the full width. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <limits>

bool test(unsigned int value, int position) {
    assert(position >= 0 && position < std::numeric_limits<unsigned int>::digits);
    return (value & (1U << position)) != 0U;
}

int main() {
    assert((12U & 10U) == 8U);
    assert((12U | 10U) == 14U);
    assert((12U ^ 10U) == 6U);
    assert(test(12U, 2));
    assert(!test(12U, 0));
    assert((12U | 1U) == 13U);
    assert((12U & ~4U) == 8U);
    assert((12U ^ 4U) == 8U);
    std::cout << "checks passed\n";
    return 0;
}
