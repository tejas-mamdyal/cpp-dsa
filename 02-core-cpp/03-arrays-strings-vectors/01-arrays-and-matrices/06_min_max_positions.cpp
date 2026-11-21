/*
REMEMBER BOTH A VALUE AND ITS POSITION
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
Initialize indices from the first actual element. A strict improvement changes an index;
equality does not, preserving the first occurrence. After each comparison, tracked
indices refer to the best values seen.

TIME AND AUXILIARY SPACE
O(n) time, fixed O(10) storage and O(1) extra working space.

BOUNDARIES AND COMMON MISTAKES
Starting the maximum at0 fails on all-negative input. Using<= or>= would select the last
occurrence instead of the requested first.

PRACTICE
1. Change the policy to last occurrence and provide a duplicate-heavy test.
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

    if (n == 0) {
        std::cout << "no data\n";
        return 0;
    }
    // These variables are indices, not element values.
    int minimum = 0;
    int maximum = 0;
    for (int i = 1; i < n; ++i) {
        if (values[i] < values[minimum]) {
            minimum = i;
        }
        if (values[i] > values[maximum]) {
            maximum = i;
        }
    }
    std::cout << values[minimum] << ' ' << minimum << '\n'
              << values[maximum] << ' ' << maximum << '\n';
}
