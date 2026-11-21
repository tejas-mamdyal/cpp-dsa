/*
RESERVE HASH CAPACITY WITHOUT PROMISING ITERATION ORDER
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Set max_load_factor before reserve; inspect bucket_count and load_factor.
Trace: reserve100 requests room for100 elements at the chosen load factor.
Why it works: reserve sizes the bucket array for a target element count under the load-factor policy.
Cost: Expected O(n) construction, O(n) memory; rehash may be expensive.
Common mistake: Rehash invalidates iterators but not references/pointers to surviving elements; erase invalidates the erased element. Collision attacks can still cause bad performance.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> values;
    values.max_load_factor(0.5F);
    values.reserve(100);
    for (int i = 0; i < 100; ++i) {
        values.emplace(i, i * i);
    }
    assert(values.size() == 100);
    assert(values.load_factor() <= values.max_load_factor());
    assert(values.at(9) == 81);
    std::cout << "checks passed\n";
}
