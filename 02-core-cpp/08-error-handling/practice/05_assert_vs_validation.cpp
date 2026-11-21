/*
ASSERTIONS CHECK PROGRAMMER ASSUMPTIONS NOT EXTERNAL INPUT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Validate external values with control flow, then assert an internal postcondition.
Trace: mark-1 returns false; mark75 succeeds.
Why it works: The guard prevents invalid mutation; the assertion documents the maintained invariant.
Cost: O(1) time and space.
Common mistake: Assertions may be disabled with NDEBUG. Never put a required user-input validation or important side effect only inside assert in production code.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

bool validateMark(int candidate, int& mark) {
    if (candidate < 0 || candidate > 100) {
        return false;
    }
    mark = candidate;
    assert(mark >= 0 && mark <= 100);
    return true;
}

int main() {
    int mark = 0;
    assert(validateMark(75, mark));
    assert(mark == 75);
    assert(!validateMark(-1, mark));
    assert(mark == 75);
    std::cout << "checks passed\n";
}
