/*
ARMSTRONG NUMBER WITH INTEGER POWERS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: For 0<=n<=1000000, test whether the sum of each digit raised to the number of digits equals n.
Trace: 153 -> 1^3+5^3+3^3=153. 0 has one digit.
Why it works: The helper encodes the definition directly and the main function exercises different boundary classes.
Cost: O(d^2) multiplications for d digits; O(1) space.
Common mistake: Keep products within long long and distinguish zero, one and negative values according to the contract.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

long long power(int base, int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

bool armstrong(int n) {
    int digits = 1;
    for (int x = n; x >= 10; x /= 10) {
        ++digits;
    }
    long long sum = 0;
    int remaining = n;
    do {
        sum += power(remaining % 10, digits);
        remaining /= 10;
    } while (remaining != 0);
    return sum == n;
}

int main() {
    std::cout << armstrong(153) << ' ' << armstrong(9474) << ' ' << armstrong(154) << ' '
              << armstrong(0) << '\n';
}
