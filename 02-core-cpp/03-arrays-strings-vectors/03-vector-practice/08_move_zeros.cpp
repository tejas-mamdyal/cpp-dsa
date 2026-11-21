/*
MOVE ZEROS TO THE END STABLY
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Overwrite nonzero values in encounter order, then fill the remaining suffix with zeros.
Trace: 0,3,0,1 ->3,1,0,0.
Why it works: write never exceeds the read position, so unread input is not overwritten.
Cost: O(n) time in the length of the data; O(1) auxiliary space.
Common mistake: Swapping every zero with the last element does not preserve nonzero order.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values = {0, 3, 0, 1};
    std::size_t write = 0;
    for (int value : values) {
        if (value != 0) {
            values[write] = value;
            ++write;
        }
    }
    while (write < values.size()) {
        values[write] = 0;
        ++write;
    }
    assert((values == std::vector<int>{3, 1, 0, 0}));
    std::cout << "checks passed\n";
}
