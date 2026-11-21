/*
BUILD AND EDIT A STRING
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use +=, push_back, insert, erase and replace with explicit positions.
Trace: cat -> cats -> Cats -> Cute -> Cut.
Why it works: Each edit addresses a valid position in the current string, not an earlier version.
Cost: O(n) time in the length of the data; O(1) auxiliary space.
Common mistake: Check empty input and bounds before indexing; valid indices end at size()-1.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

int main() {
    std::string text = "cat";
    text += 's';
    assert(text == "cats");
    text.replace(0, 1, "C");
    assert(text == "Cats");
    text.replace(1, 3, "ute");
    assert(text == "Cute");
    text.erase(3, 1);
    assert(text == "Cut");
    text.insert(0, "A ");
    text.push_back('!');
    assert(text == "A Cut!");
    std::cout << "checks passed\n";
}
