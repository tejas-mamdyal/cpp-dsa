/*
PUBLIC INHERITANCE AND A BASE REFERENCE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A public derived object may be observed through its base interface.
Trace: Student Ada is-a Person with name Ada.
Why it works: Public inheritance makes the accessible base subobject available through a reference.
Cost: O(n) name construction; O(1) observation.
Common mistake: This base is not used for polymorphic deletion; add a virtual destructor when deletion through a base pointer is possible.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

class Person {
    std::string label;

public:
    explicit Person(std::string name)
        : label(name) {
    }

    const std::string& name() const {
        return label;
    }
};

class Student : public Person {
    int number;

public:
    Student(std::string name, int roll)
        : Person(name),
          number(roll) {
    }

    int roll() const {
        return number;
    }
};

int main() {
    Student student("Ada", 7);
    const Person& person = student;
    assert(person.name() == "Ada");
    assert(student.roll() == 7);
    std::cout << "checks passed\n";
}
