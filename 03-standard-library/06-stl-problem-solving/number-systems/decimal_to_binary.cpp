/*
Convert a nonnegative decimal integer to base 2. Prerequisites: division,
remainders, loops and strings. Dividing by the base removes the least-significant
digit; the remainder is that digit. Digits are discovered in reverse order.
Example in base 2: 6 -> remainder 0, quotient 3 -> remainder 1, quotient 1
-> remainder 1, quotient 0; reverse 011 to get 110.
A do/while handles zero (one digit) correctly. A lookup table handles A..F
without switch fallthrough. Invalid or negative input is rejected explicitly.
O(log_2(n+1)) time and storage for n>0, constant for zero.
Exercise: implement the inverse with value = value*base + digit, checking overflow.
*/
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    long long n = 0;
    std::cout << "Enter a nonnegative number: ";
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Expected a nonnegative integer.\n";
        return 1;
    }
    const std::string digits = "0123456789ABCDEF";
    long long remaining = n;
    std::string answer;
    do {
        answer += digits[remaining % 2]; // Select the lowest digit.
        remaining /= 2;                  // Remove that digit, guaranteeing progress.
    } while (remaining != 0);
    std::reverse(answer.begin(), answer.end()); // Most significant digit first.
    std::cout << "Binary of " << n << " is: " << answer << '\n';
}
