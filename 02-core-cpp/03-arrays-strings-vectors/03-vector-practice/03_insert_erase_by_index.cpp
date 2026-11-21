/*
INSERT AND ERASE BY SHIFTING VECTOR ELEMENTS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Implement the shift manually before learning iterator insert/erase. Index must be valid.
Trace: 1,3 -> append slot -> shift ->1,2,3; erase index1 ->1,3.
Why it works: Backward shifts preserve unread values on insertion; forward shifts close the erasure gap.
Cost: O(n) time per middle insertion/erasure; O(1) extra space aside from vector capacity.
Common mistake: Check empty input and bounds before indexing; valid indices end at size()-1.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values = {1, 3};
    std::size_t position = 1;
    values.push_back(0);
    for (std::size_t i = values.size() - 1; i > position; --i) {
        values[i] = values[i - 1];
    }
    values[position] = 2;
    assert((values == std::vector<int>{1, 2, 3}));
    for (std::size_t i = position; i + 1 < values.size(); ++i) {
        values[i] = values[i + 1];
    }
    values.pop_back();
    assert((values == std::vector<int>{1, 3}));
    std::cout << "checks passed\n";
}
