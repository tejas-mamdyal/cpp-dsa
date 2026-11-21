/*
STANDARD MEMBERS MAKE MANUAL CLEANUP UNNECESSARY
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use a vector-owned Buffer and copy it without defining a destructor or copy operation.
Trace: changing the copied buffer leaves original data intact.
Why it works: The vector member supplies its own correct value semantics and cleanup.
Cost: O(n) copy time and storage.
Common mistake: Do not write a raw-pointer resource-owning class when a standard owner already meets the requirement.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

struct Buffer {
    std::vector<int> values;
};

int main() {
    Buffer first{{1, 2}};
    Buffer second = first;
    second.values[0] = 9;
    assert(first.values[0] == 1);
    assert(second.values[0] == 9);
    std::cout << "checks passed\n";
}
