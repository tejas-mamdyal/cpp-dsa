/*
HEAP ALGORITHMS OPERATE ON VECTOR RANGES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: make_heap establishes a max-heap; pop_heap moves its maximum to the end, then pop_back removes it.
Trace: 3,1,4 ->heap front4;pop_heap then pop_back leaves maximum3.
Why it works: Each operation preserves the heap invariant on its documented range.
Cost: make_heap O(n); push/pop O(log n); sort_heap O(n log n); in-place range storage.
Common mistake: pop_heap alone does not shrink the vector. push_heap requires that all but the newly appended element already form a heap.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> values = {3, 1, 4};
    std::make_heap(values.begin(), values.end());
    assert(values.front() == 4);
    std::pop_heap(values.begin(), values.end());
    assert(values.back() == 4);
    values.pop_back();
    assert(values.front() == 3);
    values.push_back(9);
    std::push_heap(values.begin(), values.end());
    assert(values.front() == 9);
    std::sort_heap(values.begin(), values.end());
    assert((values == std::vector<int>{1, 3, 9}));
    std::cout << "checks passed\n";
}
