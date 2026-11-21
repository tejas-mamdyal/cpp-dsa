/*
COMPARE ORIGINAL AND TRANSFORMED STATE
Route: Reinforcement | Prerequisites: Unit 04: conditions, validation and early return.

A decimal palindrome reads the same in reverse; preserve n while reversing a separate
remaining value.

O(d) time/O(1) space.

Destroying n during extraction would lose the comparison target.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int remaining = n;
    long long reversed = 0;
    do {
        reversed = reversed * 10 + remaining % 10;
        remaining /= 10;
    } while (remaining != 0);
    if (reversed == n) {
        std::cout << "palindrome\n";
    } else {
        std::cout << "not palindrome\n";
    }
}
