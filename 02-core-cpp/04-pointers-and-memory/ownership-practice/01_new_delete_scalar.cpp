/*
MATCH SCALAR NEW WITH SCALAR DELETE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Value-initialize one dynamically allocated int, modify it, and release it once.
Trace: new int(4) gives4; write9 then delete.
Why it works: Exactly one owner releases exactly one allocation.
Cost: O(1) payload storage; allocation cost is implementation-dependent.
Common mistake: Do not dereference after deletion, delete twice, or use delete[] for scalar new. Prefer automatic storage unless dynamic lifetime is needed.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int* value = new int(4);
    assert(*value == 4);
    *value = 9;
    assert(*value == 9);
    delete value;
    value = nullptr;
    assert(value == nullptr);
    std::cout << "checks passed\n";
}
