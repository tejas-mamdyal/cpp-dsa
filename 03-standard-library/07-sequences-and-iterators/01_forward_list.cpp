/*
FORWARD LIST INSERTION FOLLOWS A PREDECESSOR
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use before_begin and insert_after/erase_after on a singly linked standard container.
Trace: 1,3 -> insert2 after1 ->1,2,3 ->erase2 ->1,3.
Why it works: A predecessor iterator identifies the link being changed.
Cost: O(1) insert/erase with a known predecessor; O(n) to find it.
Common mistake: forward_list has no random access or size member. end cannot be dereferenced.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <forward_list>

int main() {
    std::forward_list<int> values = {1, 3};
    auto first = values.begin();
    auto inserted = values.insert_after(first, 2);
    assert(*inserted == 2);
    values.erase_after(first);
    auto it = values.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 3);
    std::cout << "checks passed\n";
}
