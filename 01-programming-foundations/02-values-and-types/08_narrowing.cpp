/*
A CONVERSION CAN DISCARD INFORMATION
Route: Core | Prerequisites: Unit 01: statements, variables and streams.

Casting a representable floating value to int discards the fractional part toward zero.

O(1) time and O(1) auxiliary space for these bounded examples.

This is not rounding; out-of-range floating-to-integer conversion is invalid.
*/
#include <iostream>

int main() {
    double value = 0;
    std::cin >> value;
    int whole = static_cast<int>(value); // Explicitly discard the fraction.
    std::cout << whole << "\n";
}
