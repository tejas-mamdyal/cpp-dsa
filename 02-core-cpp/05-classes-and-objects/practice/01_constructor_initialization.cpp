/*
INITIALIZE MEMBERS BEFORE THE CONSTRUCTOR BODY
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use a default constructor, explicit value constructor and initialization list.
Trace: default counter=0; explicit counter(5)=5.
Why it works: The initialization list constructs the member before any constructor-body statements run.
Cost: O(1) time and space.
Common mistake: Members initialize in declaration order, not list order. explicit rejects unintended implicit conversion.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

class Counter {
    int count;

public:
    Counter()
        : count(0) {
    }

    explicit Counter(int initial)
        : count(initial) {
    }

    int value() const {
        return count;
    }
};

int main() {
    Counter zero;
    Counter five(5);
    assert(zero.value() == 0);
    assert(five.value() == 5);
    std::cout << "checks passed\n";
}
