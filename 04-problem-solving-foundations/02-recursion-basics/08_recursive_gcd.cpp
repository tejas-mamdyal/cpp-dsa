/*
EUCLIDEAN RECURSION CHANGES TWO ARGUMENTS
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read a,b in [0,1000000000]. Print their greatest common divisor, defining gcd(0,0)=0. Reject invalid/missing input with stderr/exit1; extra later tokens are ignored.

IDEA AND STATE
The next problem is gcd(b,a%b), not gcd(a-1,b-1). Stop when the second argument is0, at which point the first argument is the answer.

TRACE
gcd(48,18) ->gcd(18,12) ->gcd(12,6) ->gcd(6,0)=6.

WHY IT WORKS AND TERMINATES
The common divisors of a,b are exactly those of b,a%b. A nonzero remainder is smaller than the previous second argument, forcing eventual termination.

O(1+log(max(a,b)+1)) remainder operations and stack frames; b=0 takes one call. This is an upper bound including zero cases, using fixed-width arithmetic.

PITFALL AND PRACTICE
The smaller argument alone is not a complete initial bound when it is0. Avoid remainder by0 by checking the base before computing a%b.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long a = 0;
    long long b = 0;
    if (!(std::cin >> a >> b) || a < 0 || a > 1000000000LL || b < 0 || b > 1000000000LL) {
        std::cerr << "Expected bounded nonnegative arguments.\n";
        return 1;
    }
    std::cout << gcd(a, b) << '\n';
    return 0;
}
