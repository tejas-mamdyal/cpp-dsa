/*
FIRST RECURSIVE FUNCTION: FACTORIAL
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read n in [0,20]. Print n! as long long. 0!=1. Invalid/missing input: diagnostic on stderr and exit1; extra later tokens are ignored. The supported long long is at least64 bits.

IDEA AND STATE
A recursive function calls itself on a smaller problem. Each active call has its own n and pending multiplication. A base case returns without another call. main validates the domain before entering the helper.

TRACE
factorial(3) waits for factorial(2), then factorial(1), then factorial(0)=1. Returns combine1*1=1,2*1=2,3*2=6.

WHY IT WORKS AND TERMINATES
The base matches the definition0!=1. Assuming the smaller call returns(n-1)!, multiplying by n returns n!. Nonnegative n decreases by1, so the base must be reached.

T(n)=T(n-1)+Theta(1), hence Theta(n+1) time and O(n+1) simultaneous stack frames. There are n+1 calls including the base. No sequence is stored.

PITFALL AND PRACTICE
An int factorial overflows much earlier;20! fits signed64-bit but21! does not. Recursion does not bypass numeric limits. Very deep linear recursion can overflow the stack; the small bound here is deliberate.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>

long long factorial(int n) {
    if (n == 0) {
        return 1;
    } // Base: no further call is made.
    long long smaller = factorial(n - 1); // This frame waits while the smaller call runs.
    return n * smaller; // Unwind: combine the returned result with this frame's n.
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || n < 0 || n > 20) {
        std::cerr << "Expected n in 0..20.\n";
        return 1;
    }
    std::cout << factorial(n) << '\n';
    return 0;
}
