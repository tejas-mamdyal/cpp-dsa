/*
SEARCH SORTED RANGES WITH BINARY SEARCH AND BOUNDS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: lower_bound finds first >=value; upper_bound first >value; their distance counts duplicates.
Trace: 1,2,2,4 ->count2=2;lower_bound3 points to4.
Why it works: Sorted order allows discarding half the remaining candidates.
Cost: O(log n) comparisons and iterator jumps on vector.
Common mistake: The range must be partitioned according to the search ordering; sorting/searching with incompatible comparators breaks the contract.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> values = {1, 2, 2, 4};
    auto lower = std::lower_bound(values.begin(), values.end(), 2);
    auto upper = std::upper_bound(values.begin(), values.end(), 2);
    assert(upper - lower == 2);
    assert(std::binary_search(values.begin(), values.end(), 4));
    assert(!std::binary_search(values.begin(), values.end(), 3));
    assert(*std::lower_bound(values.begin(), values.end(), 3) == 4);
    std::cout << "checks passed\n";
}
