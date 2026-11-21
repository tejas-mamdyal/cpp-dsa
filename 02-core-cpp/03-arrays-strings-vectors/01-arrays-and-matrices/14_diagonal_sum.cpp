/*
COUNT A SHARED CENTER ONCE
Phase2, unit1 | Route: Reinforcement
Prerequisites: Phase1 variables, conditions, loops, functions and input validation.
Read this unit's NOTES.md before the first lesson. No pointers, references,
containers, dynamic allocation or recursion are required here.

DERIVATION AND CORRECTNESS
For square dimension n, the main diagonal is c==r and the opposite diagonal is c==n-1-r.
Add the first for each row, then add the second only when it is a different cell. In an
odd square only the center coincides.

TIME AND AUXILIARY SPACE
O(n^2) total including input, O(n) diagonal computation, fixed matrix storage and O(1)
other space.

BOUNDARIES AND COMMON MISTAKES
A1x1 matrix contains one diagonal cell, not two. Reject a nonsquare input rather than
inventing a dimension convention.

PRACTICE
1. Compute the two diagonal sums separately as well as their union.
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

    if (rows != columns) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    long long sum = 0;
    for (int r = 0; r < rows; ++r) {
        sum += matrix[r][r];
        int opposite = rows - 1 - r;
        if (opposite != r) {
            sum += matrix[r][opposite];
        }
    }
    std::cout << sum << '\n';
}
