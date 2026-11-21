/*
RELATE ONE-DIMENSIONAL AND TWO-DIMENSIONAL INDICES
Phase2, unit1 | Route: Reinforcement
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
Row r starts at linear position r*columns; column c adds c. Flatten assigns
flat[r*columns+c]. Restoration uses the same index relation in reverse, so every active
cell is recovered exactly.

TIME AND AUXILIARY SPACE
O(rows*columns) time, extra fixed16-element array and4x4 matrix. General extra space
O(rows*columns).

BOUNDARIES AND COMMON MISTAKES
The active column count determines the logical flattened stride, while the physical
built-in matrix has capacity4 columns. These are different layouts when columns<4; the
explicit loops handle the mapping.

PRACTICE
1. Derive row=index/columns and column=index%columns, then test every active index.
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

    int flat[capacity * capacity]{};
    int restored[capacity][capacity]{};
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            flat[r * columns + c] = matrix[r][c];
        }
    }
    for (int i = 0; i < rows * columns; ++i) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << flat[i];
    }
    std::cout << '\n';
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            restored[r][c] = flat[r * columns + c];
            if (c) {
                std::cout << ' ';
            }
            std::cout << restored[r][c];
        }
        std::cout << '\n';
    }
}
