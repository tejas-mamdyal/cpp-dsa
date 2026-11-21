/*
SEPARATE SPACING FROM CONTENT
Route: Core | Prerequisites: Unit 05: loops and accumulators.

Row r needs n-r leading spaces followed by r stars. These two inner loops have different
roles.

O(n^2) time/O(1) space.

Leading spaces are output data; do not trim them in tests.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 10)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int r = 1; r <= n; ++r) {
        for (int s = 0; s < n - r; ++s) {
            std::cout << ' ';
        }
        for (int c = 0; c < r; ++c) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
