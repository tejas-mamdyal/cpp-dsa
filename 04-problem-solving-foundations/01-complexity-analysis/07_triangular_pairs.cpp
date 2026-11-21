/*
DEPENDENT NESTED BOUNDS FORM A SUM
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
Read n in [0,1000]. Print the selected loop-body visit count. Invalid input prints stderr and exits1; extra later tokens are ignored.

IDEA
Visit index pairs i<j, excluding self-pairs and reversed duplicates.

TRACE
n=4 contributes3+2+1+0=6 visits.

WHY IT WORKS
Each unordered pair has exactly one smaller index i and is reached exactly once. The sum is n*(n-1)/2.

Theta(n*n+1) time for this enumeration; O(1) extra storage. Computing the formula alone would take O(1) arithmetic operations.

PITFALL AND PRACTICE
Nested syntax alone does not determine cost: sum the actual inner bounds. Do not confuse unordered pairs with n*n ordered pairs.
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
        for (int j = i + 1; j < n; ++j) {
            ++visits;
        }
    }
    std::cout << visits << '\n';
    return 0;
}
