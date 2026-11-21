/*
STATIC MEMBERS BELONG TO THE CLASS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: An inline static data member is shared by objects; a static function has no this pointer.
Trace: constructing two tickets assigns consecutive IDs1,2.
Why it works: All objects increment the same class-wide counter.
Cost: O(1) time/space per construction.
Common mistake: This tiny counter has no concurrent access or overflow handling; static member access uses Class::member.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

class Ticket {
    inline static int nextId = 0;
    int number;

public:
    Ticket()
        : number(++nextId) {
    }

    int id() const {
        return number;
    }

    static int issued() {
        return nextId;
    }
};

int main() {
    Ticket first;
    Ticket second;
    assert(first.id() == 1);
    assert(second.id() == 2);
    assert(Ticket::issued() == 2);
    std::cout << "checks passed\n";
}
