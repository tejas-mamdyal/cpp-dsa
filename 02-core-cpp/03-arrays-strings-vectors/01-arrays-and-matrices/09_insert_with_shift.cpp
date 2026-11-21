/*
INSERT WITHOUT LOSING AN EXISTING VALUE
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
To make a gap at position, shift the suffix RIGHT starting from its last element.
Backward copying preserves each value before its destination overwrites storage. Then
fill the gap and increase active length.

TIME AND AUXILIARY SPACE
O(n) worst update/output time, fixed O(10) storage and O(1) extra space.

BOUNDARIES AND COMMON MISTAKES
Insertion accepts position==n, unlike access. Increasing n beyond capacity or shifting
left-to-right would respectively overflow storage or duplicate overwritten data.

PRACTICE
1. Compare insertion at the beginning, middle and end.
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
    int value = 0;
    if (!(std::cin >> position >> value) || n == capacity || position < 0 || position > n
        || value < -1000 || value > 1000) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int i = n; i > position; --i) {
        values[i] = values[i - 1]; // Backward movement protects the source suffix.
    }
    values[position] = value;
    ++n;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' '; // Separator only between active elements.
        }
        std::cout << values[i];
    }
    std::cout << '\n'; // Even an empty result is one empty line.
}
