/*
A MATRIX USES TWO INDICES
Phase2, unit1 | Route: Reinforcement
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
matrix[r][c] selects column c inside row r. The outer loop chooses a row and the inner
loop visits its columns. Physical capacity4x4 can be larger than the active rectangle.

TIME AND AUXILIARY SPACE
O(rows*columns) time, fixed O(4*4) storage and O(1) other space. General storage for
capacityR by C is O(R*C).

BOUNDARIES AND COMMON MISTAKES
Rows and columns are separate dimensions: do not use rows as both loop bounds.
Variable-length local matrices are not standard C++17.

PRACTICE
1. Print the same elements in column-first traversal without changing storage.
2. Write a smallest legal and an adversarial input; predict output before running.
*/
#include <iostream>

int main() {
    const int capacity = 4;
    int matrix[capacity][capacity]{}; // First index selects a row, second a column.
    int rows = 0;
    int columns = 0;
    if (!(std::cin >> rows >> columns) || rows < 1 || rows > capacity || columns < 1
        || columns > capacity) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (!(std::cin >> matrix[r][c]) || matrix[r][c] < -1000 || matrix[r][c] > 1000) {
                std::cerr << "Invalid input\n";
                return 1;
            }
        }
    }

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (c) {
                std::cout << ' ';
            }
            std::cout << matrix[r][c];
        }
        std::cout << '\n';
    }
}
