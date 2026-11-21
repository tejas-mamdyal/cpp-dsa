/*
A MULTIPLICATIVE ACCUMULATOR
Route: Core | Prerequisites: Unit 04: conditions, validation and early return.

Before multiplying by i, product equals (i-1)!; initialize to 1 so 0! is the empty
product.

O(n) time/O(1) space.

21! exceeds signed long long; the bound is part of correctness.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 20)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    long long product = 1;
    for (int i = 1; i <= n; ++i) {
        product *= i;
    }
    std::cout << product << '\n';
}
