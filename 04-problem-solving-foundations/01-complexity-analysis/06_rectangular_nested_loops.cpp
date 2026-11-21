/*
INDEPENDENT NESTED LOOPS MULTIPLY THEIR WORK
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
Read n,m in [0,1000]. Print the selected loop-body visit count. Invalid input prints stderr and exits1; extra later tokens are ignored.

IDEA
For each of n rows visit each of m columns; count cells without storing a matrix.

TRACE
n=3,m=4 gives12 cells; n=0 gives0 selected visits.

WHY IT WORKS
Each row contributes m visits and all n rows are distinct.

Theta(1+n+n*m) loop/control work; the counted inner operation occurs exactly n*m times. O(1) extra storage.

PITFALL AND PRACTICE
For m=0 the inner body has0 visits but the outer loop still checks n rows. Operation counts and total work are different.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>

int main() {
    int n = 0;
    int m = 0;
    if (!(std::cin >> n >> m) || n < 0 || n > 1000 || m < 0 || m > 1000) {
        std::cerr << "Invalid dimensions.\n";
        return 1;
    }
    long long visits = 0;
    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < m; ++column) {
            ++visits;
        }
    }
    std::cout << visits << '\n';
    return 0;
}
