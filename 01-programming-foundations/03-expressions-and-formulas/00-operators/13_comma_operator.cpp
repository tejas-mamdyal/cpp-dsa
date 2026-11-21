/*
COMMA OPERATOR VERSUS PUNCTUATION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A parenthesized comma expression evaluates its left expression, then returns the right expression.
Trace: value becomes 7, then result becomes value*2=14.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Commas separating arguments, declarations or initializer elements are punctuation, not the comma operator. Prefer separate statements in normal code.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int value = 0;
    int result = (value = 7, value * 2);
    std::cout << value << ' ' << result << '\n';
}
