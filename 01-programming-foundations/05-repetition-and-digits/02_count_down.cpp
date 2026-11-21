/*
A DECREASING LOOP
Route: Core | Prerequisites: Unit 04: conditions, validation and early return.

Each iteration decreases the positive remaining count, so the loop eventually reaches
zero.

O(n) time/O(1) space.

Using an unsigned counter with i>=0 can wrap and never terminate.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int i = n; i >= 1; --i) {
        std::cout << i << '\n';
    }
}
