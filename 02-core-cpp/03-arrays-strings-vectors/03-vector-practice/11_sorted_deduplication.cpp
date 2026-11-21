/*
REMOVE DUPLICATES FROM A SORTED VECTOR
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Maintain a write prefix of distinct values, then resize to that prefix.
Trace: 1,1,2,2,3 ->1,2,3.
Why it works: Equal values are adjacent in sorted input, so comparing with the last retained value is sufficient.
Cost: O(n) time in the length of the data; O(1) auxiliary space.
Common mistake: Without sorting first, this removes adjacent duplicates only; it does not remove separated duplicates.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values = {1, 1, 2, 2, 3};
    std::size_t write = 0;
    for (int value : values) {
        if (write == 0 || values[write - 1] != value) {
            values[write] = value;
            ++write;
        }
    }
    values.resize(write);
    assert((values == std::vector<int>{1, 2, 3}));
    std::cout << "checks passed\n";
}
