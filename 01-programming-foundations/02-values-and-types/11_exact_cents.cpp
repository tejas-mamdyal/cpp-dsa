/*
REPRESENT EXACT DECIMAL UNITS AS INTEGERS
Route: Reinforcement | Prerequisites: Unit 01: statements, variables and streams.

Changing the unit of representation makes the amount exact without binary floating-point
rounding.

O(1) time and O(1) auxiliary space for these bounded examples.

This contract does not parse a decimal string such as 12.35.
*/
#include <iostream>

int main() {
    long long units = 0;
    int cents = 0;
    std::cin >> units >> cents;
    std::cout << units * 100 + cents << "\n";
}
