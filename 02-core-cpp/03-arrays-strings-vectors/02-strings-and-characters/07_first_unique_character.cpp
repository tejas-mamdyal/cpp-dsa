/*
FIRST NON-REPEATING LOWERCASE CHARACTER
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Return its index or -1 using counting then a left-to-right scan.
Trace: swiss has first unique character w at index 1.
Why it works: Counts establish uniqueness, while the second scan establishes first position.
Cost: O(n+26) time, O(26) space.
Common mistake: The alphabet is a..z and the length must fit int; do not return the first alphabetically unique letter.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

int firstUnique(const std::string& text) {
    int count[26] = {};
    for (char ch : text) {
        ++count[ch - 'a'];
    }
    for (std::size_t i = 0; i < text.size(); ++i) {
        if (count[text[i] - 'a'] == 1) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    assert(firstUnique("swiss") == 1);
    assert(firstUnique("aabb") == -1);
    assert(firstUnique("") == -1);
    std::cout << "checks passed\n";
}
