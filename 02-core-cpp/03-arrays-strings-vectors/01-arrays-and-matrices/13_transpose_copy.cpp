/*
SWAP THE MEANINGS OF ROW AND COLUMN
Phase2, unit1 | Route: Reinforcement
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
The transpose places original[r][c] at transposed[c][r]. A separate matrix lets
rectangular inputs transpose without complicated in-place rearrangement. The output
dimensions must also swap.

TIME AND AUXILIARY SPACE
O(rows*columns) time; one extra fixed4x4 matrix. General extra space is O(rows*columns).

BOUNDARIES AND COMMON MISTAKES
Simply swapping indices when printing the original with the original loop bounds can
access inactive/wrong cells. Square-only swapping is not a general rectangular
transpose.

PRACTICE
1. Transpose twice and verify you recover the original dimensions and values.
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

    int transposed[capacity][capacity]{};
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            transposed[c][r] = matrix[r][c];
        }
    }
    for (int r = 0; r < columns; ++r) {
        for (int c = 0; c < rows; ++c) {
            if (c) {
                std::cout << ' ';
            }
            std::cout << transposed[r][c];
        }
        std::cout << '\n';
    }
}
