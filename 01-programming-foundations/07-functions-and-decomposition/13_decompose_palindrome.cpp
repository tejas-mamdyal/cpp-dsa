/*
BUILD A TASK FROM SMALLER NAMED STEPS
Route: Reinforcement | Prerequisites: Units 01–06: decisions, loops and repeated input.

reverseDigits transforms a value; isPalindrome compares original and transformed values;
main handles the external contract.

O(d) time/O(1) space.

A helper must not unexpectedly consume input or print when its name suggests only a
computation.
*/
#include <iostream>

long long reverseDigits(int n) {
    long long result = 0;
    do {
        result = result * 10 + n % 10;
        n /= 10;
    } while (n);
    return result;
}

bool isPalindrome(int n) {
    return reverseDigits(n) == n;
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (isPalindrome(n)) {
        std::cout << "palindrome\n";
    } else {
        std::cout << "not palindrome\n";
    }
}
