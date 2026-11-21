/*
CONST CAST CHANGES A VIEW NOT OBJECT MUTABILITY
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Remove const only from a view that actually refers to an originally mutable int.
Trace: mutable value3 observed through const int*, then restored mutable view writes4.
Why it works: The original object is mutable, so restoring a writable view here is permitted.
Cost: O(1) time and space.
Common mistake: Writing through a cast to an actually const object is undefined; prefer fixing an API rather than using const_cast.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int value = 3;
    const int* view = &value;
    int* restored = const_cast<int*>(view);
    *restored = 4;
    assert(value == 4);
    const int immutable = 9;
    assert(immutable == 9);
    std::cout << "checks passed\n";
}
