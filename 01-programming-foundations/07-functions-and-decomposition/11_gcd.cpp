/*
ENCAPSULATE A STATE-CHANGING LOOP
Route: Reinforcement | Prerequisites: Units 01–06: decisions, loops and repeated input.

Common divisors of a,b are the same as those of b,a%b; repeatedly replace the pair until
the second value is zero.

O(log(min(a,b)+1)) time for positive inputs, O(1) for a zero input; O(1) space.

Save the remainder before overwriting a.
*/
#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int a = 0;
    int b = 0;
    if (!(std::cin >> a >> b) || !(a >= 0 && a <= 1000000 && b >= 0 && b <= 1000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << gcd(a, b) << "\n";
}
