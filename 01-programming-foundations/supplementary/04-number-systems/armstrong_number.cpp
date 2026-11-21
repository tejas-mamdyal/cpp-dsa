/*
A nonnegative d-digit Armstrong number equals the sum of each digit raised to d.
153 has 3 digits: 1^3+5^3+3^3=153. Count digits by repeated division, then extract
them with %10. Zero has one digit and is Armstrong. Use integer multiplication,
not approximate floating-point pow. Restrict input to [0,1e9], so the sum fits
long long. O(d^2) time/O(1) extra space with repeated multiplication.
Exercise: precompute the ten digit powers once, reducing the digit pass to O(d).
*/
#include <iostream>

int main() {
    long long n = 0;
    std::cout << "Enter a nonnegative integer <= 1000000000: ";
    if (!(std::cin >> n) || n < 0 || n > 1000000000) {
        return 1;
    }
    int digits = 0;
    long long remaining = n;
    do {
        ++digits;
        remaining /= 10;
    } while (remaining);
    long long sum = 0;
    remaining = n;
    do {
        int digit = static_cast<int>(remaining % 10);
        long long term = 1;
        for (int i = 0; i < digits; ++i) {
            term *= digit;
        }
        sum += term;
        remaining /= 10;
    } while (remaining);
    if (sum == n) {
        std::cout << n << " is Armstrong\n";
    } else {
        std::cout << n << " is not Armstrong\n";
    }
}
