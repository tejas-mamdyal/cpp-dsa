/*
LOGICAL AND OR AND NOT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Combine boolean results with &&, || and !.
Trace: true AND false is false; true OR false is true.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Logical operators operate on truth values; bitwise operators operate on individual bits.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    bool paid = true;
    bool expired = false;
    std::cout << (paid && !expired) << ' ' << (paid || expired) << ' ' << !paid << '\n';
}
