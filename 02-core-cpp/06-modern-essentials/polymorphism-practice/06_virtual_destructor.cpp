/*
VIRTUAL DESTRUCTION CLEANS THE COMPLETE OBJECT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Observe a derived destructor through deletion by a base pointer. Raw new/delete appear only in this ownership bridge.
Trace: delete base pointer increments the derived destruction counter exactly once.
Why it works: The virtual base destructor dispatches destruction to the full dynamic object.
Cost: O(1) time/space excluding allocator overhead.
Common mistake: Read dynamic memory first. Deleting a Derived through a Base without an appropriate virtual destructor is invalid.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

struct Base {
    virtual ~Base() = default;
};

struct Derived : public Base {
    int& destroyed;

    explicit Derived(int& counter)
        : destroyed(counter) {
    }

    ~Derived() override {
        ++destroyed;
    }
};

int main() {
    int destroyed = 0;
    Base* pointer = new Derived(destroyed);
    delete pointer;
    pointer = nullptr;
    assert(destroyed == 1);
    std::cout << "checks passed\n";
}
