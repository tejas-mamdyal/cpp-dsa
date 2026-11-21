/*
ERASE BY CLOSING A GAP
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
Shift later elements LEFT in ascending source order so each earlier gap is filled.
Decrease active length; the now-unused last object still exists, but is no longer part
of the sequence.

TIME AND AUXILIARY SPACE
O(n) worst time, fixed O(10) storage and O(1) extra working space.

BOUNDARIES AND COMMON MISTAKES
Changing length does not deallocate a built-in array or clear the former last slot. Only
active elements should be printed.

PRACTICE
1. Erase the first matching value by combining search with this shift.
2. Write a smallest legal and an adversarial input; predict output before running.
*/
#include <iostream>

int main() {
    const int capacity = 10; // Storage exists for10 integers throughout this block.
    int values[capacity]{};  // {} value-initializes every element to0.
    int n = 0;               // n is the active length, not the storage capacity.
    if (!(std::cin >> n) || n < 0 || n > capacity) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> values[i]) || values[i] < -1000 || values[i] > 1000) {
            std::cerr << "Invalid input\n";
            return 1;
        }
    }

    int position = 0;
    if (!(std::cin >> position) || position < 0 || position >= n) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int i = position; i < n - 1; ++i) {
        values[i] = values[i + 1];
    }
    --n;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' '; // Separator only between active elements.
        }
        std::cout << values[i];
    }
    std::cout << '\n'; // Even an empty result is one empty line.
}
