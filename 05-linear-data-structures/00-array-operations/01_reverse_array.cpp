/*
REVERSE IN PLACE WITH AN INTERVAL INVARIANT PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable int vector. IDEA AND STATE: Swap the unsolved endpoints and move inward.
TRACE: 1,2,3,4 ->4,3,2,1. CORRECTNESS: Outside the active interval all elements already have
their reversed positions. COST: O(n) time,O(1) extra space. PITFALL: Use half-open bounds to
avoid empty size()-1 underflow. PRACTICE: Change the example, predict each state update and
add an empty/boundary case. No input unless explicitly stated. Assertions are the teaching
test harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void reverse(std::vector<int>& a) {
    std::size_t left = 0;
    std::size_t right = a.size();
    while (right - left > 1) {
        --right;
        std::swap(a[left], a[right]);
        ++left;
    }
}

int main() {
    for (std::vector<int> a : std::vector<std::vector<int>>{{}, {1}, {1, 2}, {1, 2, 3, 4}}) {
        auto expected = a;
        std::reverse(expected.begin(), expected.end());
        reverse(a);
        assert(a == expected);
        reverse(a);
        std::reverse(expected.begin(), expected.end());
        assert(a == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
