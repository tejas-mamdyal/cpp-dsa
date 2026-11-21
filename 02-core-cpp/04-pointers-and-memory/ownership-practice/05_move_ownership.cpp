/*
STD MOVE PERMITS OWNERSHIP TRANSFER
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Move a unique_ptr to transfer the resource; the source unique_ptr becomes empty.
Trace: source owns12, then destination owns12 and source is null.
Why it works: unique_ptr move transfers its stored pointer and clears the source.
Cost: O(1) transfer, no int copy/allocation.
Common mistake: std::move itself is a cast enabling a move operation. General moved-from objects are valid but have type-specific state guarantees.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <memory>
#include <utility>

int main() {
    auto source = std::make_unique<int>(12);
    auto destination = std::move(source);
    assert(!source);
    assert(*destination == 12);
    std::cout << "checks passed\n";
}
