/*
STORAGE SIZE IS AN IMPLEMENTATION PROPERTY
Route: Reinforcement | Prerequisites: Unit 01: statements, variables and streams.

sizeof produces a byte count; char occupies one C++ byte, whose bit width is
platform-dependent.

O(1) time and O(1) auxiliary space for these bounded examples.

A byte in C++ is not defined universally as eight bits.
*/
#include <iostream>

int main() {
    std::cout << (sizeof(char) == 1) << "\n";
    std::cout << (sizeof(long long) >= sizeof(int)) << "\n";
}
