/*
ALTERNATIVE SPELLINGS ARE THE SAME OPERATORS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: C++ keywords and, or, not, bitand, bitor, xor, compl, and_eq, or_eq, xor_eq and not_eq are standard alternative tokens.
Trace: 6 xor 3 is 5; and/or/not act like &&/||/!.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Alternative tokens need no special header. Most examples in this course use the symbolic spellings.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    std::cout << (true and not false) << ' ' << (false or true) << ' ' << (2 not_eq 3) << '\n';
    unsigned int value = 6U;
    std::cout << (value bitand 3U) << ' ' << (value bitor 3U) << ' ' << (value xor 3U) << ' '
              << ((compl value) bitand 7U) << '\n';
    value and_eq 3U;
    value or_eq 4U;
    value xor_eq 1U;
    std::cout << value << '\n';
}
