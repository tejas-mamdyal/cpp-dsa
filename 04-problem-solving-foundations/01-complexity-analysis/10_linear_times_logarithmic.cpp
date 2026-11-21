/*
ONE LOGARITHMIC PROCESS FOR EVERY ELEMENT
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
Read n in [0,1000]. Print the selected loop-body visit count. Invalid input prints stderr and exits1; extra later tokens are ignored.

IDEA
Run n outer iterations; inside each, repeatedly halve remaining=n while remaining>1.

TRACE
n=8 has3 halvings per outer iteration and8*3=24 selected visits.

WHY IT WORKS
Each independent outer iteration restarts remaining at n, so it repeats the same floor(log2(n)) updates for n>=1.

Theta(1+n*(1+log(n+1))) total loop work; O(1) extra storage. Selected count is0 for n=0 or1.

PITFALL AND PRACTICE
If remaining were shared across outer iterations instead of reset, this product reasoning would no longer apply.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || n < 0 || n > 1000) {
        std::cerr << "Invalid dimensions.\n";
        return 1;
    }
    long long visits = 0;
    for (int i = 0; i < n; ++i) {
        int remaining = n;
        while (remaining > 1) {
            remaining /= 2;
            ++visits;
        }
    }
    std::cout << visits << '\n';
    return 0;
}
