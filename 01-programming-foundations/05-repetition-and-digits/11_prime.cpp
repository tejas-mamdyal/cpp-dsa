/*
A LOOP CAN STOP AT A DECISIVE COUNTEREXAMPLE
Route: Reinforcement | Prerequisites: Unit 04: conditions, validation and early return.

A composite has a divisor at most sqrt(n). If none is found and n>=2, n is prime. Stop
on the first divisor.

O(sqrt(n)) time/O(1) space.

0 and 1 are not prime. d<=n/d avoids the potential overflow of d*d.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    bool prime = (n >= 2);
    for (int d = 2; d <= n / d; ++d) {
        if (n % d == 0) {
            prime = false;
            break;
        } // One divisor disproves primality.
    }
    if (prime) {
        std::cout << "prime\n";
    } else {
        std::cout << "not prime\n";
    }
}
