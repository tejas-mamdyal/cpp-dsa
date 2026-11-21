/*
VIRTUAL DISPATCH USES THE ACTUAL OBJECT TYPE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Call a virtual function through a base reference; override checks the signature.
Trace: a Dog observed as Animal still says woof.
Why it works: A virtual call uses the final override associated with the actual object.
Cost: O(1) bounded demonstration.
Common mistake: Dropping const from the override signature changes the function; override asks the compiler to reject that mismatch.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

struct Animal {
    virtual ~Animal() = default;

    virtual std::string sound() const {
        return "unknown";
    }
};

struct Dog : public Animal {
    std::string sound() const override {
        return "woof";
    }
};

int main() {
    Dog dog;
    const Animal& animal = dog;
    assert(animal.sound() == "woof");
    Animal plain;
    assert(plain.sound() == "unknown");
    std::cout << "checks passed\n";
}
