/*
THE SAME SIZE CAN REQUIRE DIFFERENT WORK
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
No input. Search a length4 vector for its first value, last value and an absent value; also search an empty vector. Print index and comparisons for each. -1 denotes absence.

IDEA
Count equality comparisons and return immediately on a match. This uses Phase2 linear traversal, not binary search.

TRACE
{4,7,9,2}: target4 ->0,1; target2 ->3,4; target8 ->-1,4; empty ->-1,0.

WHY IT WORKS
Before testing index i, all earlier indices have been rejected. A match is therefore first; exhausting all indices proves absence.

Best nonempty case Theta(1); worst Theta(n); O(1) extra space. Uniformly distributed successful positions give expected (n+1)/2 comparisons, but that distribution must be stated.

PITFALL AND PRACTICE
Average case needs a probability model. It is not the arithmetic mean of the best and worst complexities; absent searches can dominate real workloads.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>
#include <vector>
#include <cassert>

int findFirst(const std::vector<int>& values, int target, int& comparisons) {
    comparisons = 0;
    for (std::size_t i = 0; i < values.size(); ++i) {
        ++comparisons;
        if (values[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    std::vector<int> values = {4, 7, 9, 2};
    for (int target : {4, 2, 8}) {
        int comparisons = 0;
        int index = findFirst(values, target, comparisons);
        std::cout << index << ' ' << comparisons << '\n';
    }
    int comparisons = 0;
    assert(findFirst({}, 7, comparisons) == -1);
    assert(comparisons == 0);
    std::cout << -1 << ' ' << comparisons << '\n';
    return 0;
}
