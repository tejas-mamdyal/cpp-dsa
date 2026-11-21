/*
AN INNER BOUND DEPENDS ON THE ROW
Route: Core | Prerequisites: Unit 05: loops and accumulators.

The outer loop determines r; the inner loop prints exactly r symbols.

O(n^2) time/O(1) space.

Do not reuse the outer counter as the inner loop variable.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 10)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= r; ++c) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
