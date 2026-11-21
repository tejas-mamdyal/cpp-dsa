/*
NOEXCEPT OPERATOR INSPECTS A CALL CONTRACT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: noexcept(expression) is a compile-time boolean and does not execute the expression. A noexcept function promises not to let exceptions escape.
Trace: safe is declared noexcept; risky is not, regardless of its body.
Why it works: The operator examines the exception specification without evaluating a call.
Cost: O(1) runtime work; noexcept inspection itself is compile-time.
Common mistake: An escaping exception from a noexcept function terminates the program. This is not a try/catch replacement.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int safe() noexcept {
    return 7;
}

int risky() {
    return 8;
}

int main() {
    static_assert(noexcept(safe()), "safe promises no exceptions");
    static_assert(!noexcept(risky()), "risky has no promise");
    assert(safe() == 7);
    assert(risky() == 8);
    std::cout << "checks passed\n";
}
