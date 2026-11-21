/*
MULTIMAP GROUPS REPEATED KEYS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use equal_range to visit all records for one key without accidentally inserting data.
Trace: CS scores80,90 sum170; absent key produces an empty range.
Why it works: Equal keys are contiguous in the ordered range.
Cost: O(log n + k) for k matching records.
Common mistake: A multimap has no operator[] because a key may identify more than one value.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, int> marks = {{"CS", 80}, {"Math", 70}, {"CS", 90}};
    auto range = marks.equal_range("CS");
    int total = 0;
    for (auto it = range.first; it != range.second; ++it) {
        total += it->second;
    }
    assert(total == 170);
    auto missing = marks.equal_range("Art");
    assert(missing.first == missing.second);
    std::cout << "checks passed\n";
}
