/*
DOCUMENT A HELPER PRECONDITION
Route: Reinforcement | Prerequisites: Units 01–06: decisions, loops and repeated input.

After i multiplications result=base^i. The caller validates the precondition so all
products fit long long. An empty product is1.

O(exponent) time/O(1) space.

This lesson defines 0^0 as1; negative exponents require a different return model.
*/
#include <iostream>

long long power(int base, int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    int base = 0;
    int exponent = 0;
    if (!(std::cin >> base >> exponent)
        || !(base >= -10 && base <= 10 && exponent >= 0 && exponent <= 18)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << power(base, exponent) << "\n";
}
