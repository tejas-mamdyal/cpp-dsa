/*
VALIDATE AN INDEX BEFORE WRITING
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
Check the position before evaluating values[position]. A single assignment preserves all
other elements. Both lower and upper index bounds matter.

TIME AND AUXILIARY SPACE
O(n) input/output time, O(1) update time and fixed O(10) storage.

BOUNDARIES AND COMMON MISTAKES
position==n is one past the last active element. A negative index is invalid even if the
physical array has spare capacity.

PRACTICE
1. Read two validated updates and explain how repeated positions behave.
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
    int replacement = 0;
    if (!(std::cin >> position >> replacement) || position < 0 || position >= n
        || replacement < -1000 || replacement > 1000) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    values[position] = replacement; // Safe only after validation.

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' '; // Separator only between active elements.
        }
        std::cout << values[i];
    }
    std::cout << '\n'; // Even an empty result is one empty line.
}
