/*
PROJECT 2 — REUSABLE NUMBER TOOLKIT
Prerequisites: Phase 1 functions and digit loops. Input commands:
1 n -> digit count and digit sum; 2 n -> prime/not prime;
3 a b -> gcd; 0 -> quit. Every numeric operand is an integer in [0,1000000].
Missing quit or invalid command/token/range -> stderr Invalid
input, exit 1. Each successful operation prints one line; quit prints nothing.

Trace: 1 407 ->3 11; 2 9 ->not prime; 3 48 18 ->6; 0 ->exit.
Zero has one digit. Primality needs n>=2. gcd(0,0)=0 is an explicit convention.
Functions have one job; input/output validation remains in main. Passing by value
lets digit helpers consume copies without changing caller variables.
Per command: O(d) digit work, O(sqrt(n)) prime check or O(log(min(a,b)+1)) gcd
for positive inputs; O(1) space. All loops have a decreasing/increasing bound.
Follow-ups: add palindrome mode; add lcm with a zero check before division.
*/
#include <iostream>

int digitCount(int n) {
    int count = 0;
    do {
        ++count;
        n /= 10;
    } while (n);
    return count;
}

int digitSum(int n) {
    int sum = 0;
    do {
        sum += n % 10;
        n /= 10;
    } while (n);
    return sum;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int d = 2; d <= n / d; ++d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    while (b) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    while (true) {
        int choice = -1;
        if (!(std::cin >> choice)) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        if (choice == 0) {
            return 0;
        }
        int a = 0;
        int b = 0;
        if (choice < 1 || choice > 3 || !(std::cin >> a) || a < 0 || a > 1000000) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        if (choice == 1) {
            std::cout << digitCount(a) << ' ' << digitSum(a) << '\n';
        } else if (choice == 2) {
            if (isPrime(a)) {
                std::cout << "prime\n";
            } else {
                std::cout << "not prime\n";
            }
        } else {
            if (!(std::cin >> b) || b < 0 || b > 1000000) {
                std::cerr << "Invalid input\n";
                return 1;
            }
            std::cout << gcd(a, b) << '\n';
        }
    }
}
