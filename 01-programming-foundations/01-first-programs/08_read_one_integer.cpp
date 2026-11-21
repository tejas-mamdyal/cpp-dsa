/*
READ A WHOLE NUMBER
Route: Core | Prerequisites: None; read 00-start-here first.

std::cin reads standard input. >> parses a number and stores it in the named variable.

O(1) time/space for bounded input.

These early exercises assume valid input; failed extraction is taught in unit 04.
*/
#include <iostream>

int main() {
    int value = 0;     // Initialize storage before extraction.
    std::cin >> value; // Enter a whole number, then press Enter.
    std::cout << value << '\n';
}
