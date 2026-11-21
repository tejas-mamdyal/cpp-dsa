/*
GUARD A DANGEROUS EXPRESSION
Route: Reinforcement | Prerequisites: Units 01–02: streams, types and conversions.

&& evaluates its right operand only if the left is true, so % is never evaluated with a
zero divisor.

O(1) time and O(1) auxiliary space for bounded scalar input.

Bitwise & does not provide this short-circuit guard.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    bool divisible = (b != 0 && a % b == 0); // Test safety before performing remainder.
    std::cout << divisible << '\n';
}
