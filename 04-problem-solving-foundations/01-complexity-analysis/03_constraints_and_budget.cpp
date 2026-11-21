/*
USE CONSTRAINTS TO REJECT AN UNSUITABLE APPROACH
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
Read n in [0,1000000000] and a model budget in [0,1000000000000]. Print linear <n> <fits> and quadratic <n*n> <fits>, with fits as0/1. Invalid required input: stderr and exit1. Later tokens are ignored.

IDEA
Treat the budget as abstract counted operations, not seconds. Compute predicted work without actually executing n*n iterations. Both products fit signed64-bit under the contract.

TRACE
n=100000,budget=10000000: linear100000 fits; quadratic10000000000 does not.

WHY IT WORKS
A chosen operation taking n visits fits exactly when n<=budget; a model taking n*n visits fits when that count<=budget.

O(1) arithmetic operations and auxiliary space on the supported fixed-width toolchain.

PITFALL AND PRACTICE
Hardware, I/O, constants and language overhead affect time. There is no universal operations-per-second guarantee. Promote before multiplying.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>

int main() {
    long long n = 0;
    long long budget = 0;
    if (!(std::cin >> n >> budget) || n < 0 || n > 1000000000LL || budget < 0
        || budget > 1000000000000LL) {
        std::cerr << "Invalid size or budget.\n";
        return 1;
    }
    long long quadratic = n * n;
    std::cout << "linear " << n << ' ' << (n <= budget) << '\n';
    std::cout << "quadratic " << quadratic << ' ' << (quadratic <= budget) << '\n';
    return 0;
}
