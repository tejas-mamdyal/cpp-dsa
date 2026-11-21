/*
COUNT DIFFERING BIT POSITIONS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Unsigned values of the same fixed width. IDEA AND STATE: XOR marks exactly the
unequal positions; count those ones. TRACE: 10 XOR12 =6, distance2. CORRECTNESS: Equal bits
cancel and unequal bits produce1. COST: O(number of differing bits) time,O(1) space. PITFALL:
Numeric subtraction does not measure bitwise distance. PRACTICE: Change the example, predict
each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>

int distance(unsigned int a, unsigned int b) {
    unsigned int difference = a ^ b;
    int count = 0;
    while (difference != 0U) {
        difference &= difference - 1U;
        ++count;
    }
    return count;
}

int main() {
    assert(distance(10U, 12U) == 2);
    assert(distance(0U, 0U) == 0);
    assert(distance(0U, 255U) == 8);
    assert(distance(12U, 10U) == distance(10U, 12U));
    std::cout << "checks passed\n";
    return 0;
}
