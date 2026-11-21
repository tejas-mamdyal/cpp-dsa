/*
SHORT CIRCUIT PROTECTS A DIVISION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use && to test a denominator before evaluating a division.
Trace: denominator 0 makes the left operand false; the division is never evaluated.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Built-in && and || short circuit from left to right. Replacing && with & loses this protection.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int denominator = 0;
    bool valid = denominator != 0 && 20 / denominator > 2;
    std::cout << valid << '\n';
    denominator = 4;
    valid = denominator != 0 && 20 / denominator > 2;
    std::cout << valid << '\n';
}
