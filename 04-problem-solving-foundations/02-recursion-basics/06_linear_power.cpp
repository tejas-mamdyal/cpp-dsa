/*
RECURSIVE POWER BY REMOVING ONE FACTOR
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read base in [-5,5] and exponent in [0,20]. Print base^exponent, with exponent0 returning1, including the programming convention0^0=1 here. Invalid/missing input gives stderr/exit1; later tokens are ignored.

IDEA AND STATE
One recursive step removes one factor of base. The exponent controls the recursion depth; the numeric result is not the input-size measure.

TRACE
power(-2,3)=-2*power(-2,2)=-2*4=-8; exponent0 stops with1.

WHY IT WORKS AND TERMINATES
The empty product is1. Multiplying a correct exponent(e-1) result by base gives exponent e. Nonnegative exponent decreases to0.

Theta(e+1) time, O(e+1) stack space for exponent e. All products fit signed64-bit under the bounds.

PITFALL AND PRACTICE
The ^ token means bitwise XOR in C++, not exponentiation. Negative exponents need a different result type/contract. A loop is simpler when recursion adds no benefit.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>

long long linearPower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * linearPower(base, exponent - 1);
}

int main() {
    int base = 0;
    int exponent = 0;
    if (!(std::cin >> base >> exponent) || base < -5 || base > 5 || exponent < 0 || exponent > 20) {
        std::cerr << "Invalid base or exponent.\n";
        return 1;
    }
    std::cout << linearPower(base, exponent) << '\n';
    return 0;
}
