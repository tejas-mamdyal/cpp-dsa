/*
mutable on a lambda allows changing its by-value captured copies; it does not change the original variables. A reference capture aliases its target instead. The lifetime of any referenced object must cover the call.
*/
/*
MUTABLE AND INITIALIZED CAPTURES OWN THEIR STATE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: An init capture can create a separate counter; mutable permits modifying a captured copy.
Trace: counter starts0 and successive calls return1,2; outer value stays10.
Why it works: The closure retains its own counter between calls.
Cost: O(1) time/storage.
Common mistake: mutable changes captured copies, not the original variable captured by value.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int outer = 10;
    auto next = [counter = 0, outer]() mutable {
        ++counter;
        return counter + outer;
    };
    assert(next() == 11);
    assert(next() == 12);
    assert(outer == 10);
    std::cout << "checks passed\n";
}
