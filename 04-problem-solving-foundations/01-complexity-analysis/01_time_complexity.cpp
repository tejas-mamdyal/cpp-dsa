/*
COUNT WORK INSTEAD OF GUESSING ELAPSED TIME
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
No input. Compare element-read counts for a guarded first-element access, a complete scan, and every ordered index pair, using sizes 0,1,5.

IDEA
Choose a counted operation first. Count only value reads/pair visits here, not every machine instruction. Size-zero still has constant guard/setup overhead.

TRACE
n=5: first reads1, scan reads5, pair visits25. n=0: all selected counts are0.

WHY IT WORKS
A scan visits each index once. Nested independent loops combine every outer index with every inner index, giving n*n ordered pairs, including equal indices.

First access Theta(1); scan Theta(n+1); pair enumeration Theta(n*n+1). Counts are exact for the selected operation. O(1) auxiliary storage; input vectors take O(n).

PITFALL AND PRACTICE
An upper bound O(n*n) for a linear scan is true but loose. Prefer a tight Theta bound when known. Avoid claiming an exact wall-clock runtime.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>
#include <vector>

int firstReads(const std::vector<int>& values) {
    if (values.empty()) {
        return 0;
    }
    int observed = values[0];
    (void)observed;
    return 1;
}

int scanReads(const std::vector<int>& values) {
    int count = 0;
    for (int value : values) {
        (void)value;
        ++count;
    }
    return count;
}

long long pairVisits(const std::vector<int>& values) {
    long long count = 0;
    for (std::size_t i = 0; i < values.size(); ++i) {
        for (std::size_t j = 0; j < values.size(); ++j) {
            ++count;
        }
    }
    return count;
}

int main() {
    for (int n : {0, 1, 5}) {
        std::vector<int> values(static_cast<std::size_t>(n), 7);
        std::cout << n << ' ' << firstReads(values) << ' ' << scanReads(values) << ' '
                  << pairVisits(values) << '\n';
    }
    return 0;
}
