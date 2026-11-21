/*
DECIMAL INPUT AND OUTPUT FORMATTING
Route: Core | Prerequisites: Unit 01: statements, variables and streams.

fixed selects fixed-point notation; setprecision(2) requests two digits after the
decimal point.

O(1) time and O(1) auxiliary space for these bounded examples.

Formatting is not exact decimal arithmetic.
*/
#include <iostream>
#include <iomanip>

int main() {
    double value = 0;
    std::cin >> value;
    std::cout << std::fixed << std::setprecision(2) << value << "\n";
}
