/*
NULL POINTER AS AN ABSENT OBSERVATION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use nullptr for absence and test before dereferencing. The pointer does not own the local value.
Trace: nullptr produces fallback 0; address of 8 produces 8.
Why it works: The guard returns before any dereference of an absent pointer.
Cost: O(1) time and space.
Common mistake: A non-null pointer may still dangle; validity also depends on lifetime.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int readOrZero(const int* pointer) {
    if (pointer == nullptr) {
        return 0;
    }
    return *pointer;
}

int main() {
    int value = 8;
    assert(readOrZero(nullptr) == 0);
    assert(readOrZero(&value) == 8);
    std::cout << "checks passed\n";
}
