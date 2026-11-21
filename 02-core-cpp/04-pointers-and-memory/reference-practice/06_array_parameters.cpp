/*
ARRAY PARAMETERS REQUIRE A SEPARATE LENGTH
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: An int array parameter adjusts to a pointer and loses its array extent. Pass a length explicitly.
Trace: sum first 3 elements = 12; length 0 never dereferences the pointer.
Why it works: The caller supplies an in-bounds length; the loop reads exactly that many elements.
Cost: O(n) time and O(1) space.
Common mistake: sizeof(values) inside this function is a pointer size, not the caller array size.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int total(const int values[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += values[i];
    }
    return sum;
}

int main() {
    int values[3] = {2, 4, 6};
    assert(total(values, 3) == 12);
    assert(total(nullptr, 0) == 0);
    std::cout << "checks passed\n";
}
