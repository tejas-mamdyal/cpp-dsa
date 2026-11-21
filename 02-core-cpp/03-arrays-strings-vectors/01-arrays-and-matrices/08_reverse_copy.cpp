/*
COPY IN A DIFFERENT ORDER
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
Output position i corresponds to original n-1-i. Only the second array is assigned, so
the original remains available unchanged. This establishes the distinction between
making a copy and modifying the source.

TIME AND AUXILIARY SPACE
O(n) time and an additional fixed O(10) copy. A general length-n copy needs O(n) extra
storage.

BOUNDARIES AND COMMON MISTAKES
Built-in arrays cannot be copied by writing reversed=values. Copy their elements. The
empty loop must not evaluate n-1-i for any element access.

PRACTICE
1. Print the original first and confirm that copying did not alter it.
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

    int reversed[capacity]{};
    for (int i = 0; i < n; ++i) {
        reversed[i] = values[n - 1 - i];
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << reversed[i];
    }
    std::cout << '\n';

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' '; // Separator only between active elements.
        }
        std::cout << values[i];
    }
    std::cout << '\n'; // Even an empty result is one empty line.
}
