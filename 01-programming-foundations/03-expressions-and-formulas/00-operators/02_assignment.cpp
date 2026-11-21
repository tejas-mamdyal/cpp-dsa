/*
ASSIGNMENT AND ARITHMETIC COMPOUND ASSIGNMENT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Update a variable with =, +=, -=, *=, /= and %=; print each state.
Trace: 10 -> 15 -> 12 -> 24 -> 6 -> 2.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Do not combine several modifications of the same variable in one expression.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int value = 10;
    value += 5;
    std::cout << value << ' ';
    value -= 3;
    std::cout << value << ' ';
    value *= 2;
    std::cout << value << ' ';
    value /= 4;
    std::cout << value << ' ';
    value %= 4;
    std::cout << value << '\n';
}
