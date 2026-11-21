/*
PERFECT NUMBERS AND DIGIT-FACTORIAL NUMBERS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Check two different definitions: sum of proper positive divisors, and sum of digit factorials. n is 0..1000000.
Trace: 6=1+2+3;145=1!+4!+5!. 0!=1.
Why it works: The helper encodes the definition directly and the main function exercises different boundary classes.
Cost: Perfect baseline O(n), digit-factorial O(d) with a fixed 9-step inner bound; O(1) space.
Common mistake: Keep products within long long and distinguish zero, one and negative values according to the contract.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

bool perfect(int n) {
    if (n < 2) {
        return false;
    }
    int sum = 1;
    for (int divisor = 2; divisor <= n / 2; ++divisor) {
        if (n % divisor == 0) {
            sum += divisor;
        }
    }
    return sum == n;
}

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

bool strong(int n) {
    int original = n;
    int sum = 0;
    do {
        sum += factorial(n % 10);
        n /= 10;
    } while (n != 0);
    return sum == original;
}

int main() {
    std::cout << perfect(6) << ' ' << perfect(28) << ' ' << perfect(1) << '\n';
    std::cout << strong(145) << ' ' << strong(123) << ' ' << strong(0) << '\n';
}
