/*
COUNT ONE FULL SCAN
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
Read n in [0,1000], then n ints in [-1000,1000]. Print their sum and number of element visits. Reject invalid/missing required input before printing; extra later tokens are ignored.

IDEA
Combine a running sum with a visit counter. No input vector is necessary because the aggregate needs no previous elements.

TRACE
n=3,values4,-1,2: sums4,3,5; visits1,2,3 ->5 3.

WHY IT WORKS
Each successful iteration adds exactly its one new value and increments the count once. After n iterations every required value is included once.

Theta(n+1) integer extractions and loop work; O(1) auxiliary storage. Numeric text length also affects parsing cost.

PITFALL AND PRACTICE
A loop count describes the selected operation, not the precise number of CPU instructions. Sum bounds are safe in long long.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || n < 0 || n > 1000) {
        std::cerr << "Invalid count.\n";
        return 1;
    }
    long long sum = 0;
    int visits = 0;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        if (!(std::cin >> value) || value < -1000 || value > 1000) {
            std::cerr << "Invalid value.\n";
            return 1;
        }
        sum += value;
        ++visits;
    }
    std::cout << sum << ' ' << visits << '\n';
    return 0;
}
