/*
SCOPED ENUMERATIONS EXPRESS VALID CHOICES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: enum class keeps named values scoped and avoids implicit int conversion.
Trace: Status::passed selects a passed message.
Why it works: A scoped enum gives the state a dedicated type and named alternatives.
Cost: O(1) time and space.
Common mistake: Do not assume arbitrary integers represent valid enum states; validate external numeric input.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

enum class Status {
    pending,
    passed,
    failed
};

bool isPassed(Status status) {
    return status == Status::passed;
}

int main() {
    Status status = Status::passed;
    assert(isPassed(status));
    assert(!isPassed(Status::pending));
    assert(static_cast<int>(Status::failed) == 2);
    std::cout << "checks passed\n";
}
