/*
CORRECT AN EXCLUDED ENDPOINT
Route: Core | Prerequisites: Units 01–07; functions and input validation.

Using i<=n includes the requested endpoint; the loop invariant is sum of1..i-1 before
adding i.

O(n) time; O(1) auxiliary space.

Boundary tests often reveal off-by-one errors.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i; // Include the stated endpoint.
    }
    std::cout << sum << '\n';
}
