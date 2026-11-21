/*
BITWISE AND OR XOR COMPLEMENT AND SHIFTS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use unsigned integers to inspect bits. 12 is 1100 in binary and 10 is 1010.
Trace: 12&10=8, 12|10=14, 12^10=6; (~12)&15 keeps only four bits.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Shift counts must be nonnegative and smaller than the promoted left operand width. Unsigned left shift wraps modulo 2^width; use representable shifts when multiplying.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    unsigned int a = 12U;
    unsigned int b = 10U;
    std::cout << (a & b) << ' ' << (a | b) << ' ' << (a ^ b) << ' ' << ((~a) & 15U) << '\n';
    std::cout << (a << 1) << ' ' << (a >> 2) << '\n';
}
