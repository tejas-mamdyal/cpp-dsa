/*
SEQUENTIAL LOOPS ADD THEIR WORK
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
Read n,m in [0,1000]. Print the selected loop-body visit count. Invalid input prints stderr and exits1; extra later tokens are ignored.

IDEA
Execute one loop n times and then another m times; both update the same counter.

TRACE
n=3,m=4 gives3+4=7 visits.

WHY IT WORKS
The second loop is not inside the first. Its work is added once, not repeated for every first-loop iteration.

Theta(n+m+1) time, O(1) extra space. With unrelated input sizes keep both variables.

PITFALL AND PRACTICE
O(n) is only appropriate after defining a relationship between n and m or defining a combined size.
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
    for (int i = 0; i < n; ++i) {
        ++visits;
    }
    for (int j = 0; j < m; ++j) {
        ++visits;
    }
    std::cout << visits << '\n';
    return 0;
}
