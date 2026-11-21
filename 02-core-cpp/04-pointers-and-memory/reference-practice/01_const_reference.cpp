/*
READ-ONLY REFERENCE PARAMETERS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A const reference observes an existing int without permitting writes through that alias.
Trace: value=7 is observed twice without changing the caller.
Why it works: The const qualifier forbids changing the referred-to int through this parameter.
Cost: O(1) time and space.
Common mistake: Do not return a reference to a local variable or a temporary that will expire.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int twice(const int& value) {
    return value * 2;
}

int main() {
    int value = 7;
    assert(twice(value) == 14);
    assert(value == 7);
    assert(twice(0) == 0);
    std::cout << "checks passed\n";
}
