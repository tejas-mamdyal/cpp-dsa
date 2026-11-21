/*
ITERATOR INSERT AND ERASE RETURN POSITIONS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use vector insert/erase after the iterator introduction; capture returned iterators.
Trace: 1,3 ->insert2 ->1,2,3 ->erase2 ->1,3.
Why it works: The returned iterator is valid after that particular modification and identifies the changed position.
Cost: O(n) shifts per middle insert/erase, O(n) vector storage.
Common mistake: Insertion can invalidate all iterators on reallocation; do not reuse earlier iterators.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values = {1, 3};
    auto position = values.insert(values.begin() + 1, 2);
    assert(*position == 2);
    position = values.erase(position);
    assert(*position == 3);
    assert((values == std::vector<int>{1, 3}));
    std::cout << "checks passed\n";
}
