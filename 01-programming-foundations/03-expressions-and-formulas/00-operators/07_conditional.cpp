/*
THE CONDITIONAL OPERATOR CHOOSES ONE VALUE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use condition ? first : second for a small value selection. Only the chosen branch is evaluated.
Trace: -8 < 0 selects 8; an unchosen division by zero is not evaluated.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: For the most negative int, negation overflows. This example deliberately uses -8. Prefer if/else for multi-step actions.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int value = -8;
    int magnitude = value < 0 ? -value : value;
    int denominator = 0;
    int quotient = denominator == 0 ? 0 : 20 / denominator;
    std::cout << magnitude << ' ' << quotient << '\n';
}
