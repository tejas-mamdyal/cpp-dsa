/*
REPEATED HALVING CREATES LOGARITHMIC WORK
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
Read n in [0,1000000000]. Print the selected iteration count. Invalid input gives stderr/exit1; extra later tokens are ignored.

IDEA
Divide a remaining positive size by2 until it reaches0.

TRACE
n=13:13,6,3,1 ->4 iterations; n=0 ->0.

WHY IT WORKS
After k divisions remaining is floor(n/2^k). For n>0 it reaches0 after floor(log2(n))+1 iterations.

Theta(1+log(n+1)) fixed-width loop work; O(1) auxiliary storage. The explicit +1 covers setup and zero.

PITFALL AND PRACTICE
Use integer loops for exact counts rather than rounding a floating log. Doubling storage is long long and the input bound prevents overflow.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || n < 0 || n > 1000000000) {
        std::cerr << "Invalid size.\n";
        return 1;
    }
    int remaining = n;
    int steps = 0;
    while (remaining > 0) {
        remaining /= 2;
        ++steps;
    }
    std::cout << steps << '\n';
    return 0;
}
