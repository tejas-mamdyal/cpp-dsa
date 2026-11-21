/*
REPAIR THE ACCUMULATOR IDENTITY
Route: Core | Prerequisites: Units 01–07; functions and input validation.

Multiplication must start at1; starting at0 makes every later product0.

O(n) time; O(1) auxiliary space.

Test an empty iteration range as well as a normal one.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 20)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    long long result = 1; // Multiplicative identity, not zero.
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    std::cout << result << '\n';
}
