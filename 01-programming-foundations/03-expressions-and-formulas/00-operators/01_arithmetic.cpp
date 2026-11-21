/*
ARITHMETIC AND UNARY SIGNS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Compute +, -, *, /, %, unary + and unary - on small integers. No input.
Trace: 17/5 is 3; 17%5 is 2; -17/5 truncates toward zero.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: Division/remainder by zero and signed integer overflow are undefined. ^ is not exponentiation.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int a = 17;
    int b = 5;
    std::cout << a + b << ' ' << a - b << ' ' << a * b << '\n';
    std::cout << a / b << ' ' << a % b << ' ' << -a << ' ' << +b << '\n';
    std::cout << -17 / 5 << ' ' << -17 % 5 << '\n';
}
