/*
FUNCTION OBJECTS AND TYPED WRAPPERS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A class operator() carries state; std::function can hold compatible callable kinds.
Trace: Scale3 applied4=12; wrapper replaced with add1 gives5.
Why it works: All stored operations accept an int and return an int.
Cost: O(1) bounded callable state; std::function may allocate and adds indirect-call overhead.
Common mistake: Calling an empty std::function throws bad_function_call. Use a named function or auto lambda when type erasure is unnecessary.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <functional>

struct Scale {
    int factor;

    int operator()(int value) const {
        return value * factor;
    }
};

int main() {
    Scale triple{3};
    assert(triple(4) == 12);
    std::function<int(int)> operation = triple;
    assert(operation(4) == 12);
    operation = [](int value) {
        return value + 1;
    };
    assert(operation(4) == 5);
    std::cout << "checks passed\n";
}
