/*
HANDLE AN OPERATION-SPECIFIC FAILURE
Route: Reinforcement | Prerequisites: Units 01–03: values, expressions and bool.

A valid number is not necessarily a legal divisor. Branch before division to prevent
undefined behavior.

O(1) time and O(1) auxiliary space.

Checking the divisor after evaluating division is too late.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    if (!(std::cin >> a >> b) || !(a >= -1000 && a <= 1000 && b >= -1000 && b <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (b == 0) {
        std::cout << "undefined\n";
    } else {
        std::cout << a / b << '\n';
    }
}
