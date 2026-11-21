/*
CONDITIONS INSIDE NESTED LOOPS
Route: Core | Prerequisites: Unit 05: loops and accumulators.

A cell is on the border when its row or column equals either extreme index.

O(n^2) time/O(1) space.

For n=1 every cell is a border; do not special-case it incorrectly.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 1 && n <= 10)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (r == 0 || r == n - 1 || c == 0 || c == n - 1) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
