/*
CHECKED DOWNCASTS AND RUNTIME TYPE INFORMATION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: dynamic_cast on a polymorphic pointer returns nullptr for a failed cast; typeid inspects dynamic type.
Trace: Dog pointer succeeds for Dog object and fails for plain Animal.
Why it works: The virtual base enables runtime type checking instead of guessing the derived type.
Cost: Runtime cast cost depends on implementation and hierarchy; O(1) example storage.
Common mistake: A failed reference dynamic_cast throws bad_cast; a failed pointer cast yields nullptr. Prefer virtual methods when they express the operation directly.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <typeinfo>

struct Animal {
    virtual ~Animal() = default;
};

struct Dog : public Animal {};

int main() {
    Dog dog;
    Animal plain;
    Animal* pointer = &dog;
    assert(dynamic_cast<Dog*>(pointer) != nullptr);
    assert(typeid(*pointer) == typeid(Dog));
    pointer = &plain;
    assert(dynamic_cast<Dog*>(pointer) == nullptr);
    std::cout << "checks passed\n";
}
