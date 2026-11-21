/*
TEXT VERSUS CALCULATION
Route: Core | Prerequisites: None; read 00-start-here first.

Inside quotes, characters are printed literally. Outside quotes, + adds numeric operands
before output.

O(1) time/space.

Printing "2+3" does not ask the computer to evaluate arithmetic.
*/
#include <iostream>

int main() {
    std::cout << "2 + 3\n";     // Describe the expression.
    std::cout << 2 + 3 << '\n'; // Evaluate it.
}
