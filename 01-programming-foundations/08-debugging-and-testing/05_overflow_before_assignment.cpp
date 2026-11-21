/*
WIDEN BEFORE MULTIPLICATION
Route: Core | Prerequisites: Units 01–07; functions and input validation.

The expression type determines arithmetic;1LL forces the product to be formed in long
long.

O(1) time and O(1) auxiliary space.

Signed overflow is undefined behavior, not a portable wraparound rule.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    if (!(std::cin >> a >> b) || !(a >= 0 && a <= 1000000 && b >= 0 && b <= 1000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    long long product = 1LL * a * b;
    std::cout << product << '\n';
}
