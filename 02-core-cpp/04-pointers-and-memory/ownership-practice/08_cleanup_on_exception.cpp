/*
RAII CLEANS UP DURING EXCEPTION PROPAGATION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Throw after constructing a guard and observe cleanup before catch.
Trace: active counter1 in try,0 by catch.
Why it works: Stack unwinding invokes destructors of fully constructed automatic objects.
Cost: O(1) demonstration state; exception runtime costs are implementation-dependent.
Common mistake: Read exception basics before this bridge. A leaked raw new allocation has no automatic cleanup unless an owner was established.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <stdexcept>

struct Guard {
    int& active;

    explicit Guard(int& count)
        : active(count) {
        ++active;
    }

    ~Guard() {
        --active;
    }
};

int main() {
    int active = 0;
    bool caught = false;
    try {
        Guard guard(active);
        assert(active == 1);
        throw std::runtime_error("stop");
    } catch (const std::runtime_error&) {
        caught = true;
    }
    assert(caught);
    assert(active == 0);
    std::cout << "checks passed\n";
}
