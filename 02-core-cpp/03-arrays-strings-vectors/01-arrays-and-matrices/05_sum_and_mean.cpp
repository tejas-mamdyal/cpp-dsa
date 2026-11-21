/*
COMPUTE AGGREGATES FROM STORED VALUES
Phase2, unit1 | Route: Core
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
After processing i elements, sum equals the sum of values[0..i). Check emptiness before
dividing; convert sum before /n to avoid integer truncation. Unlike Phase1 streaming,
retaining the array permits later passes.

TIME AND AUXILIARY SPACE
O(n) time, fixed O(10) storage and O(1) working space.

BOUNDARIES AND COMMON MISTAKES
A mean for an empty sequence is not zero by default. The input bounds keep sum safe, but
long long demonstrates a wider aggregate type.

PRACTICE
1. Also report how many elements exceed the mean.
2. Write a smallest legal and an adversarial input; predict output before running.
*/
#include <iostream>
#include <iomanip>

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
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += values[i];
    }
    double mean = static_cast<double>(sum) / n;
    std::cout << sum << ' ' << std::fixed << std::setprecision(2) << mean << '\n';
}
