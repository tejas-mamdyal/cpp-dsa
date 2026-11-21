/*
HASH FREQUENCY COUNTS AND NON-INSERTING QUERIES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use [] to increment, find to query without insertion, and at for an existing key.
Trace: 4,4,1 gives count4=2 and count1=1.
Why it works: Each occurrence increments its own key counter once.
Cost: Expected O(n) total updates, worst O(n^2) under pathological collisions; O(u) keys.
Common mistake: Hash iteration order is unspecified; do not use it as sorted output.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> counts;
    for (int value : {4, 4, 1}) {
        ++counts[value];
    }
    assert(counts.at(4) == 2);
    std::size_t before = counts.size();
    assert(counts.find(9) == counts.end());
    assert(counts.size() == before);
    std::cout << "checks passed\n";
}
