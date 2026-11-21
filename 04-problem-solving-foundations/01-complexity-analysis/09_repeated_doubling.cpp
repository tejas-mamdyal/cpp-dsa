/*
REPEATED DOUBLING ALSO CREATES LOGARITHMIC WORK
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
Read n in [0,1000000000]. Print the selected iteration count. Invalid input gives stderr/exit1; extra later tokens are ignored.

IDEA
Visit powers1,2,4,... not exceeding n.

TRACE
n=13 visits1,2,4,8 ->4; n=16 visits five powers.

WHY IT WORKS
After k updates the power is2^k; each new iteration requires a distinct power within the bound.

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
    int steps = 0;
    for (long long power = 1; power <= n; power *= 2) {
        ++steps;
    }
    std::cout << steps << '\n';
    return 0;
}
