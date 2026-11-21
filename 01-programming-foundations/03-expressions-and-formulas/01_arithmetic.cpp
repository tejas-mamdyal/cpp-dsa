/*
FOUR ARITHMETIC OPERATIONS
Route: Core | Prerequisites: Units 01–02: streams, types and conversions.

Each operation uses the same saved inputs; integer quotient discards the fractional
part.

O(1) time and O(1) auxiliary space for bounded scalar input.

Division by zero is outside this early contract.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 1;
    std::cin >> a >> b;
    std::cout << a + b << ' ' << a - b << ' ' << a * b << ' ' << a / b << '\n';
}
