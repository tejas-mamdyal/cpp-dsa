/*
MATRIX MULTIPLICATION COMBINES A ROW AND COLUMN
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Multiply A[r][k] by B[k][c] and add over k. This 2x2 demonstration uses small int entries.
Trace: [1,2;3,4]*[5,6;7,8]=[19,22;43,50].
Why it works: Each result cell is the dot product of exactly one A row and B column.
Cost: O(r*k*c) time and O(r*c) result storage.
Common mistake: Matrix multiplication is not elementwise multiplication; compatible inner dimensions are required.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int result[2][2] = {};
    for (int row = 0; row < 2; ++row) {
        for (int column = 0; column < 2; ++column) {
            for (int k = 0; k < 2; ++k) {
                result[row][column] += a[row][k] * b[k][column];
            }
        }
    }
    assert(result[0][0] == 19 && result[0][1] == 22);
    assert(result[1][0] == 43 && result[1][1] == 50);
    std::cout << "checks passed\n";
}
