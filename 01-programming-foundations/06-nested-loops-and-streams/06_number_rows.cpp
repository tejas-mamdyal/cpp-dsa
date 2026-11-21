/*
GENERATE VALUES FROM COLUMN INDICES
Route: Core | Prerequisites: Unit 05: loops and accumulators.

The column number is the value printed; the row controls how many columns exist.

O(n^2) time/O(1) space.

The bound n<=9 keeps each printed item a single digit.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 9)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= r; ++c) {
            std::cout << c;
        }
        std::cout << '\n';
    }
}
