/*
static_assert(condition,message) checks a constant expression during compilation and rejects a false condition. assert checks a running program and may be disabled with NDEBUG; static_assert cannot validate runtime input.
*/
/*
COMPILE-TIME FUNCTIONS AND PERSISTENT LOCAL STATE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: constexpr permits constant evaluation; a static local retains state across calls.
Trace: square4 checked at compile time; nextId returns1 then2.
Why it works: The constexpr body is valid in a constant expression; static local initialization happens once.
Cost: O(1) per call, O(1) persistent storage.
Common mistake: A constexpr function may also run at runtime; static local state complicates independent testing and concurrent mutation.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

constexpr int square(int value) {
    return value * value;
}

int nextId() {
    static int last = 0;
    return ++last;
}

int main() {
    static_assert(square(4) == 16, "compile-time square");
    int runtime = 3;
    assert(square(runtime) == 9);
    assert(nextId() == 1);
    assert(nextId() == 2);
    std::cout << "checks passed\n";
}
