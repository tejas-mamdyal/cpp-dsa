/*
REVERSE AND CONST ITERATORS HAVE DIFFERENT INTERFACES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: rbegin starts at the last element; cbegin disallows mutation through its iterator.
Trace: reverse copy of1,2,3 is3,2,1.
Why it works: Reverse iterator increments move toward the original range beginning.
Cost: O(n) time and O(n) result storage.
Common mistake: rend is a sentinel, not a dereferenceable element. Reverse base() points one position after the element represented.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values = {1, 2, 3};
    std::vector<int> reverse;
    for (auto it = values.rbegin(); it != values.rend(); ++it) {
        reverse.push_back(*it);
    }
    assert((reverse == std::vector<int>{3, 2, 1}));
    auto readOnly = values.cbegin();
    assert(*readOnly == 1);
    std::cout << "checks passed\n";
}
