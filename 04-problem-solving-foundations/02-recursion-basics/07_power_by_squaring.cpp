/*
HALVE THE EXPONENT AND REUSE THE RETURNED ANSWER
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
No input. Compare recursive power with an independent multiplication loop for all bases[-2,2] and exponents[0,60]. Print checked305 powers. This contract defines0^0=1 and keeps every product in signed64-bit range.

IDEA AND STATE
Compute one half-power, square it, then multiply by base only for an odd exponent. Save the half result instead of recursively calculating it twice.

TRACE
power(2,5):half=power(2,2)=4, square=16, odd adjustment=32.

WHY IT WORKS AND TERMINATES
For even e=2k, b^e=(b^k)^2; for odd e=2k+1, multiply that square by b. floor(e/2) decreases for e>0 and e=0 returns1.

T(e)=T(floor(e/2))+Theta(1): Theta(1+log(e+1)) time and stack space. The bounded oracle harness performs305 comparisons; its loop oracle is linear in e.

PITFALL AND PRACTICE
Calling power(base,e/2) twice discards the work-saving reuse and yields O(e) calls. Stack overflow and integer overflow are separate issues; check both.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>
#include <cassert>

long long fastPower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    long long half = fastPower(base, exponent / 2);
    long long result = half * half;
    if (exponent % 2 != 0) {
        result *= base;
    }
    return result;
}

long long loopPower(int base, int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    int checked = 0;
    for (int base = -2; base <= 2; ++base) {
        for (int exponent = 0; exponent <= 60; ++exponent) {
            assert(fastPower(base, exponent) == loopPower(base, exponent));
            ++checked;
        }
    }
    assert(checked == 305);
    assert(fastPower(2, 60) == 1152921504606846976LL);
    std::cout << "checked " << checked << " powers\n";
    return 0;
}
