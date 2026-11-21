/*
INITIALIZATION, CAPACITY AND ACTIVE LENGTH
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
A partially braced initializer zero-initializes the remaining int elements. Capacity is
allocated space; active length is the part the application currently treats as
meaningful data. They are different quantities.

TIME AND AUXILIARY SPACE
O(capacity) traversal time; O(capacity) array storage and O(1) other working space. Here
capacity5 is fixed.

BOUNDARIES AND COMMON MISTAKES
int values[5]; without an initializer does not initialize local ints; reading one before
assignment is invalid. Zero padding is not automatically part of the active input
sequence.

PRACTICE
1. Change active length to0 and explain why storage still exists.
2. Write a smallest legal and an adversarial input; predict output before running.
*/
#include <iostream>

int main() {
    const int capacity = 5;
    int values[capacity] = {7, 8}; // Unspecified elements in this initializer become0.
    int active = 2;
    std::cout << capacity << ' ' << active << '\n';
    for (int i = 0; i < capacity; ++i) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
}
