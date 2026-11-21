/*
VALUE COPIES SLICE BUT REFERENCES PRESERVE DISPATCH
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Copying a Derived into Base creates only a Base object; references retain the original object.
Trace: derived.kind=2; sliced.kind=1; borrowed.kind=2.
Why it works: The sliced value owns no derived subobject, while the reference still denotes the complete Derived.
Cost: O(1) bounded example.
Common mistake: Pass polymorphic objects by reference/pointer when you need virtual behavior.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

struct Base {
    virtual ~Base() = default;

    virtual int kind() const {
        return 1;
    }
};

struct Derived : public Base {
    int kind() const override {
        return 2;
    }
};

int main() {
    Derived derived;
    Base sliced = derived;
    const Base& borrowed = derived;
    assert(sliced.kind() == 1);
    assert(borrowed.kind() == 2);
    std::cout << "checks passed\n";
}
