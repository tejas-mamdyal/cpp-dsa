/*
SEARCH BY EXAMINING CANDIDATES IN ORDER
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
Before iteration i, all earlier positions have been ruled out. On equality, i is
therefore the first match; break avoids unnecessary further checks. No match leaves the
explicit absent sentinel -1.

TIME AND AUXILIARY SPACE
O(n) worst time, O(1) best search time, fixed O(10) storage and O(1) extra space.

BOUNDARIES AND COMMON MISTAKES
-1 is an answer code, not an index to dereference. This search does not require sorted
input.

PRACTICE
1. Return the last matching index without stopping early.
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

    int target = 0;
    if (!(std::cin >> target) || target < -1000 || target > 1000) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int answer = -1;
    for (int i = 0; i < n; ++i) {
        if (values[i] == target) {
            answer = i;
            break;
        }
    }
    std::cout << answer << '\n';
}
