/*
UNIQUE_PTR EXPRESSES EXCLUSIVE OWNERSHIP
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: make_unique creates a resource with one owner; get borrows, reset destroys.
Trace: owned value7; reset produces an empty owner.
Why it works: unique_ptr automatically deletes its resource when reset or destroyed.
Cost: O(1) payload and ownership bookkeeping.
Common mistake: Do not construct a second owner from owner.get() or call delete on the borrowed pointer.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <memory>

int main() {
    std::unique_ptr<int> owner = std::make_unique<int>(7);
    int* borrowed = owner.get();
    assert(*borrowed == 7);
    owner.reset();
    assert(!owner);
    // borrowed is now dangling; do not use it.

    std::cout << "checks passed\n";
}
