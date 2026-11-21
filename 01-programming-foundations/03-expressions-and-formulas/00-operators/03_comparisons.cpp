/*
ALL SIX COMPARISONS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Compare 4 and 7 with ==, !=, <, <=, >, >=. bool prints as 0 or 1.
Trace: 4 is smaller than 7, not equal.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Use == to compare and = to assign. Write low <= x && x <= high, never low <= x <= high.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int a = 4;
    int b = 7;
    std::cout << (a == b) << ' ' << (a != b) << ' ' << (a < b) << ' ' << (a <= b) << ' ' << (a > b)
              << ' ' << (a >= b) << '\n';
}
