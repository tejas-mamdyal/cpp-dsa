/*
PREFIX AND POSTFIX INCREMENT AND DECREMENT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Compare the returned value and stored value of ++x, x++, --x and x--.
Trace: x=5; post=x++ stores 5 in post and leaves x=6.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Do not combine several modifications of the same variable in one expression.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int x = 5;
    int old = x++;
    std::cout << old << ' ' << x << '\n';
    int current = ++x;
    std::cout << current << ' ' << x << '\n';
    old = x--;
    std::cout << old << ' ' << x << '\n';
    current = --x;
    std::cout << current << ' ' << x << '\n';
}
