/*
NAMED CONSTANTS
Route: Core | Prerequisites: Unit 01: statements, variables and streams.

A named const encodes a fixed conversion factor and prevents accidental reassignment.

O(1) time and O(1) auxiliary space for these bounded examples.

A const variable must be initialized.
*/
#include <iostream>

int main() {
    const int secondsPerMinute = 60;
    int minutes = 0;
    std::cin >> minutes;
    std::cout << minutes * secondsPerMinute << "\n";
}
