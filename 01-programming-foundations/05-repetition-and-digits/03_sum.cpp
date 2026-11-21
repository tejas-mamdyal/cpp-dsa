/*
AN ADDITIVE ACCUMULATOR
Route: Core | Prerequisites: Unit 04: conditions, validation and early return.

Before each iteration sum contains 1..i-1; adding i extends that invariant. Zero is the
empty sum.

O(n) time/O(1) space; the result uses long long.

A sum initialized to one double-counts the first term.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    std::cout << sum << '\n';
}
