/*
MATCH ARRAY NEW WITH DELETE BRACKETS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Allocate three value-initialized ints and release with delete[].
Trace: zero-initialized values become2,4,6 and sum12.
Why it works: The allocation creates n ints; the matching array deletion ends their lifetimes.
Cost: O(n) initialization and O(n) allocated storage.
Common mistake: delete and delete[] are not interchangeable. Prefer vector for resizable sequences.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int length = 3;
    int* values = new int[length]{};
    assert(values[0] == 0);
    for (int i = 0; i < length; ++i) {
        values[i] = 2 * (i + 1);
    }
    assert(values[0] + values[1] + values[2] == 12);
    delete[] values;
    values = nullptr;
    std::cout << "checks passed\n";
}
