/*
RULE OF ZERO FOR VALUE-OWNED RECORDS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A class containing string and vector gets safe independent copies automatically.
Trace: copy name and marks; editing the copy does not alter the original.
Why it works: Each standard container copies its owned elements.
Cost: O(name length + number of marks) time and storage for the copy.
Common mistake: A class holding a raw owning pointer would need an ownership design; do not add manual copy/destructor code to this value-only record.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::vector<int> marks;
};

int main() {
    Student first{"Ada", {80, 90}};
    Student second = first;
    second.name = "Grace";
    second.marks[0] = 100;
    assert(first.name == "Ada");
    assert(first.marks[0] == 80);
    assert(second.marks[0] == 100);
    std::cout << "checks passed\n";
}
