/*
MAP INDEXING INSERTS A MISSING KEY
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use find for observation and [] when intentional default insertion is useful.
Trace: find missing keeps size0; counts[7] creates value0.
Why it works: operator[] inserts a value-initialized mapped value only if the key is absent.
Cost: O(log n) map operations.
Common mistake: Observation through [] can silently change the container.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <map>

int main() {
    std::map<int, int> counts;
    assert(counts.find(7) == counts.end());
    assert(counts.empty());
    int observed = counts[7];
    assert(observed == 0 && counts.size() == 1);
    counts[7] += 2;
    assert(counts.at(7) == 2);
    auto inserted = counts.emplace(7, 99);
    assert(!inserted.second);
    assert(counts.at(7) == 2);
    std::cout << "checks passed\n";
}
