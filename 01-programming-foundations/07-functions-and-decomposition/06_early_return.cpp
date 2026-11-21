/*
REJECT A CANDIDATE EARLY
Route: Core | Prerequisites: Units 01–06: decisions, loops and repeated input.

Values below2 fail immediately; the first divisor also returns false. Reaching the end
proves no divisor was found.

O(sqrt(n)) time/O(1) space.

Returning true inside the divisor loop would accept numbers before all candidates were
checked.
*/
#include <iostream>

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int d = 2; d <= n / d; ++d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true; // All possible divisors have been ruled out.
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (isPrime(n)) {
        std::cout << "prime\n";
    } else {
        std::cout << "not prime\n";
    }
}
