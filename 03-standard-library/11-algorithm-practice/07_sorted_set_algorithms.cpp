/*
SORTED SET ALGORITHMS INCLUDE MULTIPLICITIES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use set_intersection and set_difference on sorted ranges; duplicates are counted, not silently discarded.
Trace: 1,2,2,3 intersect2,2,4 gives2,2; difference gives1,3.
Why it works: Sorted heads identify whether the next value is shared or exclusive.
Cost: O(n+m) comparisons and O(n+m) output capacity.
Common mistake: Both ranges must use the same ordering. set_difference is directional: a-b differs from b-a.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> a = {1, 2, 2, 3};
    std::vector<int> b = {2, 2, 4};
    std::vector<int> common;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(common));
    assert((common == std::vector<int>{2, 2}));
    std::vector<int> difference;
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(difference));
    assert((difference == std::vector<int>{1, 3}));
    std::cout << "checks passed\n";
}
