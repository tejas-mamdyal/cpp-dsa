/*
READ ONLY WITHIN ALLOCATED STORAGE
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
Validate n before using it as a loop bound. At every extraction,0<=i<n<=capacity, so
values[i] names an allocated object. Printing only0..n-1 prevents unused storage from
appearing as data.

TIME AND AUXILIARY SPACE
O(n) time, fixed O(10) array storage and O(1) other space. In a general capacityC
implementation, allocated storage is O(C), not O(n) when n<C.

BOUNDARIES AND COMMON MISTAKES
C++17 does not provide standard variable-length local arrays such as int a[n]. Use a
compile-time capacity here; vectors are taught later.

PRACTICE
1. Print the logical length on a separate line.
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

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' '; // Separator only between active elements.
        }
        std::cout << values[i];
    }
    std::cout << '\n'; // Even an empty result is one empty line.
}
