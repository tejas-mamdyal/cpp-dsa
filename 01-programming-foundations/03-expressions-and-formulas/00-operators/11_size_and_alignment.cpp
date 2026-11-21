/*
SIZEOF AND ALIGNOF WITHOUT GUESSING SIZES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: sizeof gives size in bytes; sizeof(char) is 1 by definition. alignof reports a type alignment.
Trace: sizeof(char)==1; sizeof(int)>=sizeof(char); alignof(int)>0.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: A byte is not guaranteed to be 8 bits; CHAR_BIT gives its bit count. sizeof(pointer) is not the length of a pointed-to array.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    std::cout << sizeof(char) << ' ' << (sizeof(int) >= sizeof(char)) << ' ' << (alignof(int) > 0)
              << '\n';
    int value = 5;
    (void)sizeof(value++); // sizeof does not evaluate this ordinary operand.
    std::cout << value << '\n';
}
