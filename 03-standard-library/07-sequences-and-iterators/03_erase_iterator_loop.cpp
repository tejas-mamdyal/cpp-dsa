/*
ERASE WHILE ITERATING WITHOUT INVALID ACCESS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use the iterator returned by erase instead of incrementing a destroyed iterator.
Trace: 1,2,4,3 -> remove evens ->1,3.
Why it works: erase returns the next valid position, including end when the tail is removed.
Cost: O(n^2) worst case for repeated vector erasures; O(1) extra space.
Common mistake: The later erase-remove idiom avoids repeated shifts; this lesson focuses on safe iterator control flow.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values = {1, 2, 4, 3};
    for (auto it = values.begin(); it != values.end();) {
        if (*it % 2 == 0) {
            it = values.erase(it);
        } else {
            ++it;
        }
    }
    assert((values == std::vector<int>{1, 3}));
    std::cout << "checks passed\n";
}
