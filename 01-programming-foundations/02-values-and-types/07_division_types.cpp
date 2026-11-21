/*
static_cast<Type>(expression) explicitly converts a value before later arithmetic. Converting after integer division cannot recover the discarded fraction; narrowing conversions can lose information.
*/
/*
INTEGER AND FLOATING-POINT DIVISION
Route: Core | Prerequisites: Unit 01: statements, variables and streams.

Two integer operands use integer division; static_cast<double>(a) makes the second
division real-valued.

O(1) time and O(1) auxiliary space for these bounded examples.

The cast must occur before division, not after it.
*/
#include <iostream>
#include <iomanip>

int main() {
    int a = 0;
    int b = 1;
    std::cin >> a >> b;
    std::cout << a / b << "\n";
    std::cout << std::fixed << std::setprecision(2) << static_cast<double>(a) / b << "\n";
}
