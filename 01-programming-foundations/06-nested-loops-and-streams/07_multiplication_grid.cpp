/*
TWO INDEPENDENT DIMENSIONS
Route: Core | Prerequisites: Unit 05: loops and accumulators.

Cell (r,c) is r*c. Print separators before every column except the first to avoid
trailing spaces.

O(n^2) time/O(1) space.

A newline belongs after the complete row, not after every value.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 1 && n <= 5)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            if (c > 1) {
                std::cout << ' ';
            }
            std::cout << r * c;
        }
        std::cout << '\n';
    }
}
