/*
MULTIPLICATION TABLE
Route: Core | Prerequisites: Unit 04: conditions, validation and early return.

A fixed ten-iteration loop applies the same multiplication to successive multipliers.

O(1) time/space because exactly ten products are printed.

A fixed-length loop is constant time relative to the numeric input.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= -100 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int multiplier = 1; multiplier <= 10; ++multiplier) {
        std::cout << n * multiplier << '\n';
    }
}
