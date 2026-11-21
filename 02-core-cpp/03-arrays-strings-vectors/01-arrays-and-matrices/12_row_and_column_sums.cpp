/*
RESET AGGREGATES AT THE RIGHT NESTING LEVEL
Phase2, unit1 | Route: Reinforcement
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
For a row aggregate, fix r and traverse every c; reset sum for each new r. For columns
swap the roles. Two full passes remain O(rows*columns), not its square.

TIME AND AUXILIARY SPACE
O(rows*columns) time, fixed matrix storage and O(1) additional working space.

BOUNDARIES AND COMMON MISTAKES
A sum initialized outside all outer iterations would accumulate multiple rows instead of
reporting each row separately. Include negative and nonsquare matrices.

PRACTICE
1. Find the first row with the largest sum.
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
        long long sum = 0;
        for (int c = 0; c < columns; ++c) {
            sum += matrix[r][c];
        }
        if (r) {
            std::cout << ' ';
        }
        std::cout << sum;
    }
    std::cout << '\n';
    for (int c = 0; c < columns; ++c) {
        long long sum = 0;
        for (int r = 0; r < rows; ++r) {
            sum += matrix[r][c];
        }
        if (c) {
            std::cout << ' ';
        }
        std::cout << sum;
    }
    std::cout << '\n';
}
