/*
STRING CONSTRUCTION AND CHECKED ACCESS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Construct empty, repeated and literal strings; inspect size, front, back and at.
Trace: hello has length 5; at(1) is e.
Why it works: A string owns its characters and knows its length.
Cost: O(n) construction and O(1) indexed access.
Common mistake: Check empty input and bounds before indexing; valid indices end at size()-1.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

int main() {
    std::string empty;
    std::string text = "hello";
    std::string repeated(3, 'x');
    assert(empty.empty());
    assert(text.size() == 5);
    assert(text.front() == 'h');
    assert(text.back() == 'o');
    assert(text.at(1) == 'e');
    assert(repeated == "xxx");
    std::cout << "checks passed\n";
}
