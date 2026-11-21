/*
SHRINK THE PRINTED REGION
Route: Core | Prerequisites: Unit 05: loops and accumulators.

For each row length, the inner loop prints that many stars; decreasing length guarantees
progress.

O(n^2) time/O(1) space.

The last row contains one star; a zero-length extra row is not required.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 10)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int length = n; length >= 1; --length) {
        for (int c = 0; c < length; ++c) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
