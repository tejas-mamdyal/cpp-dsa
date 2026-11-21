/*
DEFINE A SMALLER ANSWER BEFORE COMBINING IT
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read n in [0,100]. Print1+...+n, defining the empty sum at n=0 as0. Invalid/missing input gives stderr/exit1; later tokens are ignored.

IDEA AND STATE
The return value solves a complete subproblem: sumTo(n-1) contains every required term except n. Add that final term when the smaller call returns.

TRACE
sumTo(3)=3+sumTo(2)=3+2+sumTo(1)=3+2+1+sumTo(0)=6.

WHY IT WORKS AND TERMINATES
The empty sum is0. Adding n to the correct smaller sum yields the required sum; n decreases toward0.

Theta(n+1) time and O(n+1) stack space. An iterative accumulator uses O(1) auxiliary space; the closed formula uses O(1) bounded arithmetic operations.

PITFALL AND PRACTICE
This is a recursion exercise, not the best arithmetic method for huge n. Never validate only after starting the recursive calls.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>

long long sumTo(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumTo(n - 1);
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || n < 0 || n > 100) {
        std::cerr << "Expected n in 0..100.\n";
        return 1;
    }
    std::cout << sumTo(n) << '\n';
    return 0;
}
