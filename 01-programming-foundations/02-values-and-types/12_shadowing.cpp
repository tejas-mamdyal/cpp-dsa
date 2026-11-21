/*
AN INNER NAME CAN HIDE AN OUTER ONE
Route: Reinforcement | Prerequisites: Unit 01: statements, variables and streams.

Braces introduce a nested scope. The inner value is a different variable whose lifetime
ends at the closing brace.

O(1) time and O(1) auxiliary space for these bounded examples.

Shadowing is legal but can obscure intent; prefer distinct names in larger programs.
*/
#include <iostream>

int main() {
    int value = 5;
    std::cout << value << "\n";
    {
        int value = 9; // Separate object in a nested scope.
        std::cout << value << "\n";
    }
    std::cout << value << "\n";
}
