/*
AVOID RETURNING A DANGLING REFERENCE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Return a value for newly computed results; borrow by reference only from an object that outlives the call.
Trace: local computation returns 12 by value; borrowed caller int changes from 4 to 9.
Why it works: The returned reference still refers to the caller-owned int, not a destroyed local.
Cost: O(1) time and space.
Common mistake: Never return int& bound to computed local storage; no dangling dereference is executed here.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int computed() {
    int local = 12;
    return local;
}

int& borrow(int& value) {
    return value;
}

int main() {
    int value = 4;
    int& alias = borrow(value);
    alias = 9;
    assert(value == 9);
    assert(computed() == 12);
    std::cout << "checks passed\n";
}
