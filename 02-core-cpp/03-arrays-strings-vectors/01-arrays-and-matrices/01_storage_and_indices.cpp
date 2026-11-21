/*
AN ARRAY STORES RELATED VALUES UNDER ONE NAME
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
int values[5] creates five contiguous int objects with indices0..4. values[i] names one
element. Reading does not modify it; assignment changes that element. A loop replaces
repeated hand-written output statements.

TIME AND AUXILIARY SPACE
O(k) time for traversing k elements, O(1) extra space beyond the array; k=5 is fixed
here. The array itself uses O(k) storage.

BOUNDARIES AND COMMON MISTAKES
The first index is0, so the third element is index2. An out-of-bounds index is undefined
behavior: it may crash, corrupt data, or appear to work. Never try one as an experiment
outside a debugger/sanitizer lab.

PRACTICE
1. Change the final element and predict which output entries change.
2. Write a smallest legal and an adversarial input; predict output before running.
*/
#include <iostream>

int main() {
    int values[5] = {10, 20, 30, 40, 50}; // Initialization supplies every element.
    std::cout << values[0] << ' ' << values[2] << '\n';
    values[1] = 99; // Modify only the second element.
    for (int i = 0; i < 5; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
}
