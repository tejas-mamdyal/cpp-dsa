/*
REDUCE A NUMBER BY REMOVING ITS LAST DIGIT
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read a nonnegative integer at most1000000000000000000. Print the sum of its decimal digits. Reject invalid/missing/overflowed input with stderr/exit1; later tokens are ignored.

IDEA AND STATE
The last digit is n%10; n/10 is the shorter prefix. A one-digit number is already its own digit sum, including0.

TRACE
407 ->7+digitSum(40) ->7+0+digitSum(4)=11.

WHY IT WORKS AND TERMINATES
Decimal division removes one digit for n>=10. The base returns the single remaining digit, and each removed digit is added exactly once.

Theta(d) time and O(d) stack space for d decimal digits;0 counts as one digit. The contract permits at most19 digits.

PITFALL AND PRACTICE
Converting a negative minimum integer by negation may overflow; this contract instead rejects negatives. Do not confuse digit count with numeric magnitude.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>

int digitSum(long long n) {
    if (n < 10) {
        return static_cast<int>(n);
    }
    return static_cast<int>(n % 10) + digitSum(n / 10);
}

int main() {
    long long n = 0;
    if (!(std::cin >> n) || n < 0 || n > 1000000000000000000LL) {
        std::cerr << "Expected a bounded nonnegative number.\n";
        return 1;
    }
    std::cout << digitSum(n) << '\n';
    return 0;
}
