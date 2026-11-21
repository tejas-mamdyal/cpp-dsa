/*
INITIALIZATION AND LATER ASSIGNMENT
Route: Core | Prerequisites: Unit 01: statements, variables and streams.

Initialization creates the first state; assignment changes it.

O(1) time and O(1) auxiliary space for these bounded examples.

Do not confuse declaration with assignment.
*/
#include <iostream>

int main() {
    int coins = 10; // First value.
    std::cout << coins << "\n";
    coins = 15; // Replace it.
    std::cout << coins << "\n";
}
