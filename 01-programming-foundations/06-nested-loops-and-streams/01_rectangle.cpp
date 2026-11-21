/*
RECTANGULAR REPETITION
Route: Core | Prerequisites: Unit 05: loops and accumulators.

Every outer iteration emits one row; the inner loop emits exactly cols symbols.

O(rows*cols+rows) time/O(1) space, including newlines.

Place the row newline outside the inner loop.
*/
#include <iostream>

int main() {
    int rows = 0;
    int cols = 0;
    if (!(std::cin >> rows >> cols) || !(rows >= 0 && rows <= 10 && cols >= 0 && cols <= 10)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
