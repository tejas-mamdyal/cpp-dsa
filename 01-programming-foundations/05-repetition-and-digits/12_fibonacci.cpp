/*
TRACK TWO CONSECUTIVE TERMS
Route: Reinforcement | Prerequisites: Unit 04: conditions, validation and early return.

Before iteration i, a=Fi and b=F(i+1). Save a+b, then shift the pair. Bounded n keeps
every calculated value safe.

O(n) time/O(1) space.

Updating a before computing a+b loses an operand unless a temporary is used.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 50)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    long long a = 0;
    long long b = 1;
    for (int i = 0; i < n; ++i) {
        std::cout << a << '\n';
        long long next = a + b;
        a = b;
        b = next;
    }
}
