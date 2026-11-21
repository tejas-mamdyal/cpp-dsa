/*
VECTOR COPIES OWN SEPARATE ELEMENTS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Contrast a copy, reference and const-reference view.
Trace: copy changes to 9 without changing source; alias then changes source to 7.
Why it works: Copy construction creates a new owned sequence; references denote the existing object.
Cost: O(n) time/storage for a copy; O(1) to create references.
Common mistake: A const view does not freeze other aliases; it only forbids writes through that view.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> source = {1, 2};
    std::vector<int> copy = source;
    copy[0] = 9;
    assert(source[0] == 1);
    std::vector<int>& alias = source;
    alias[0] = 7;
    const std::vector<int>& view = source;
    assert(view[0] == 7);
    assert(copy[0] == 9);
    std::cout << "checks passed\n";
}
