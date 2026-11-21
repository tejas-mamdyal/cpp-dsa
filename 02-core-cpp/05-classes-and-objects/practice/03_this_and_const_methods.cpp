/*
THIS DISTINGUISHES A MEMBER FROM A PARAMETER
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: this points to the current object; const member functions can observe a const object.
Trace: set(7) stores7; a const counter initialized3 reports3.
Why it works: this->count names the member while count alone names the parameter.
Cost: O(1) time and space.
Common mistake: A const method cannot modify ordinary members or call non-const methods on its own object.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

class Counter {
    int count;

public:
    explicit Counter(int count)
        : count(count) {
    }

    void set(int count) {
        this->count = count;
    }

    int value() const {
        return count;
    }
};

int main() {
    Counter counter(1);
    counter.set(7);
    assert(counter.value() == 7);
    const Counter fixed(3);
    assert(fixed.value() == 3);
    std::cout << "checks passed\n";
}
