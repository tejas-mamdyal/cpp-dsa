/*
ALL BITWISE COMPOUND ASSIGNMENTS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use &=, |=, ^=, <<= and >>= one statement at a time.
Trace: 12 -> 8 -> 11 -> 14 -> 28 -> 7.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Do not combine several modifications of the same variable in one expression.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    unsigned int bits = 12U;
    bits &= 10U;
    std::cout << bits << ' ';
    bits |= 3U;
    std::cout << bits << ' ';
    bits ^= 5U;
    std::cout << bits << ' ';
    bits <<= 1;
    std::cout << bits << ' ';
    bits >>= 2;
    std::cout << bits << '\n';
}
