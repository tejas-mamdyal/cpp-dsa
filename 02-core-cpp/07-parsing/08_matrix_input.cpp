/*
READ A DIMENSION-PREFIXED MATRIX
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read rows and columns in [1,10], then rows*columns ints. Print the matrix with one row per line. Reject missing values or invalid dimensions.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
The dimensions describe the shape; nested loops describe input order. A nested vector retains the complete matrix, so no output is produced until all required values are valid. vector<vector<int>> is a vector of rows, where each row is a vector<int>. The constructor below creates rows copies of a row containing columns zero-initialized ints. This revisits the fixed-capacity matrix unit with runtime-sized storage.

TRACE
2 3 then 1 2 3 4 5 6 -> a 2x3 matrix, printed as two rows.

COST AND PRACTICE
O(rows * columns) integer reads, output operations and stored integers. Dimensions are at most 10.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>
#include <vector>

int main() {
    int rows = 0;
    int columns = 0;
    if (!(std::cin >> rows >> columns) || rows < 1 || rows > 10 || columns < 1 || columns > 10) {
        std::cerr << "Invalid dimensions.\n";
        return 1;
    }
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (!(std::cin >> matrix[row][column])) {
                std::cerr << "Missing or invalid matrix value.\n";
                return 1;
            }
        }
    }
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (column > 0) {
                std::cout << ' ';
            }
            std::cout << matrix[row][column];
        }
        std::cout << '\n';
    }
}
