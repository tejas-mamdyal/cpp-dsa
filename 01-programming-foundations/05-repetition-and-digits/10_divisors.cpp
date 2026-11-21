/*
TEST CANDIDATES WITH REMAINDER
Route: Reinforcement | Prerequisites: Unit 04: conditions, validation and early return.

Every divisor is between 1 and n. Check all candidates and print those with zero
remainder.

O(n) time/O(1) space.

Zero has infinitely many nonzero divisors; exclude it from this finite listing task.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 1 && n <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0) {
            std::cout << d << '\n';
        }
    }
}
