/*
CAPTURE VALUE VERSUS REFERENCE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Copy one offset and borrow another; changing the source only changes the borrowed view.
Trace: offset2 ->5; copied add1 gives3 while borrowed gives6.
Why it works: The copied capture stores its own int; the reference capture observes the original.
Cost: O(1) time and closure storage.
Common mistake: Never return a closure borrowing a destroyed local.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int offset = 2;
    auto copied = [offset](int value) {
        return value + offset;
    };
    auto borrowed = [&offset](int value) {
        return value + offset;
    };
    offset = 5;
    assert(copied(1) == 3);
    assert(borrowed(1) == 6);
    std::cout << "checks passed\n";
}
