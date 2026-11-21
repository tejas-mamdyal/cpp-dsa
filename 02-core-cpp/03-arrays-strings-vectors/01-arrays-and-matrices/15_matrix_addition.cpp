/*
COMBINE CORRESPONDING CELLS
Phase2, unit1 | Route: Reinforcement
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
Matrix addition pairs values at identical row/column positions. Dimensions must agree;
the contract supplies them once for both matrices. Separate output storage preserves
both inputs.

TIME AND AUXILIARY SPACE
O(rows*columns) time and two additional fixed4x4 matrices; general extra storage
O(rows*columns).

BOUNDARIES AND COMMON MISTAKES
Addition is not matrix multiplication. A linear index must not mix up row and column
ordering. Bounds ensure every cell sum fits int.

PRACTICE
1. Print the difference matrix without changing either input.
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

    int second[capacity][capacity]{};
    int result[capacity][capacity]{};
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (!(std::cin >> second[r][c]) || second[r][c] < -1000 || second[r][c] > 1000) {
                std::cerr << "Invalid input\n";
                return 1;
            }
            result[r][c] = matrix[r][c] + second[r][c];
        }
    }
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (c) {
                std::cout << ' ';
            }
            std::cout << result[r][c];
        }
        std::cout << '\n';
    }
}
