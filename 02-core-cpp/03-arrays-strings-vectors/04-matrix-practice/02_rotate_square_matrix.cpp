/*
ROTATE A SQUARE MATRIX CLOCKWISE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Copy source cell row,column to result[column][n-1-row].
Trace: [1,2;3,4] becomes[3,1;4,2].
Why it works: The destination formula maps each input position to its rotated position uniquely.
Cost: O(n^2) time and O(n^2) result storage.
Common mistake: For a rectangular matrix the output dimensions must be exchanged; this example deliberately uses a square.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int source[2][2] = {{1, 2}, {3, 4}};
    int result[2][2] = {};
    for (int row = 0; row < 2; ++row) {
        for (int column = 0; column < 2; ++column) {
            result[column][1 - row] = source[row][column];
        }
    }
    assert(result[0][0] == 3 && result[0][1] == 1);
    assert(result[1][0] == 4 && result[1][1] == 2);
    std::cout << "checks passed\n";
}
