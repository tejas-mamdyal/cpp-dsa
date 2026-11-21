/*
PRECEDENCE AND GROUPING
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Show multiplication before addition and parentheses before multiplication.
Trace: 2+3*4=14 while (2+3)*4=20.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Precedence groups expressions; it does not generally specify the order in which operands execute.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    std::cout << 2 + 3 * 4 << ' ' << (2 + 3) * 4 << '\n';
    std::cout << (true || (false && false)) << ' ' << ((true || false) && false) << '\n';
}
