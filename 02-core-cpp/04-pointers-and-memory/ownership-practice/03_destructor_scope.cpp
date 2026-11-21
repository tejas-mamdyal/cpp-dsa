/*
DESTRUCTORS RUN WHEN AUTOMATIC OBJECTS LEAVE SCOPE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use a local scope and a destruction counter to observe deterministic cleanup.
Trace: counter0 inside scope; counter1 after leaving.
Why it works: The automatic object is destroyed at the closing brace.
Cost: O(1) time and space.
Common mistake: The referenced counter must outlive the Guard. A destructor should not throw during stack unwinding.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

struct Guard {
    int& counter;

    explicit Guard(int& value)
        : counter(value) {
    }

    ~Guard() {
        ++counter;
    }
};

int main() {
    int destroyed = 0;
    {
        Guard guard(destroyed);
        assert(destroyed == 0);
    }
    assert(destroyed == 1);
    std::cout << "checks passed\n";
}
