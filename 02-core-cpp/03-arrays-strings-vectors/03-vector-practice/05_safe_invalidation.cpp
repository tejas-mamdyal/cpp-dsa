/*
REALLOCATION INVALIDATES VECTOR ELEMENT REFERENCES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Keep a numeric index across capacity changes, then reacquire an element reference.
Trace: index1 still names the value 20 after reserve; the old pointer must not be reused.
Why it works: Numeric positions survive relocation if the element order and size stay unchanged.
Cost: O(n) reserve time and allocation; O(1) indexed lookup.
Common mistake: Insert/erase can change positions too. A saved index is not a universal stable element identifier.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values = {10, 20};
    std::size_t index = 1;
    int saved = values[index];
    std::size_t oldCapacity = values.capacity();
    values.reserve(oldCapacity + 10);
    // No old pointer/reference is dereferenced after reserve.
    assert(values[index] == saved);
    values[index] = 25;
    assert(values[1] == 25);
    std::cout << "checks passed\n";
}
