/*
SIZE CAPACITY RESERVE AND RESIZE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Reserve changes allocation capacity, resize changes the number of elements.
Trace: reserve(8) leaves size 0; resize(3,7) creates 7,7,7.
Why it works: Capacity describes storage; size describes live elements.
Cost: reserve/resize may take O(n) time and O(n) allocated storage.
Common mistake: After reserve alone, values[0] is still out of bounds. Exact capacity growth is implementation-defined.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values;
    values.reserve(8);
    assert(values.empty());
    assert(values.capacity() >= 8);
    values.resize(3, 7);
    assert(values.size() == 3);
    assert(values[2] == 7);
    values.resize(1);
    assert(values[0] == 7);
    std::cout << "checks passed\n";
}
