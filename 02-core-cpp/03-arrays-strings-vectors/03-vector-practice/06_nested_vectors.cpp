/*
NESTED AND RAGGED VECTORS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Create a matrix, then append a shorter row. Rows own independent vectors.
Trace: two rows of three zeros; matrix[1][2]=7; third row contains only 9.
Why it works: Each row is a separate vector copy, so modifying one row does not change another.
Cost: O(r*c) for a rectangular construction and storage.
Common mistake: Use each row size when traversing a ragged matrix; matrix[2][1] is invalid here.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<std::vector<int>> matrix(2, std::vector<int>(3, 0));
    matrix[1][2] = 7;
    assert(matrix[0][2] == 0);
    assert(matrix[1][2] == 7);
    matrix.push_back({9});
    assert(matrix[2].size() == 1);
    std::cout << "checks passed\n";
}
