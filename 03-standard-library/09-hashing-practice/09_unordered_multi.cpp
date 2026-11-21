/*
HASH MULTI-CONTAINERS RETAIN DUPLICATE KEYS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: unordered_multiset stores repeated values and unordered_multimap stores repeated associations.
Trace: two5 values remain distinct occurrences; key1 maps to10 and20.
Why it works: Multi-container insertion does not discard an existing equivalent key.
Cost: Expected O(1) single lookup plus O(k) matches; worst O(n); O(n) stored records.
Common mistake: Hash iteration order is unspecified. erase(key) removes all equivalent entries; erase(iterator) removes one.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

int main() {
    std::unordered_multiset<int> values = {5, 5, 7};
    assert(values.count(5) == 2);
    auto one = values.find(5);
    values.erase(one);
    assert(values.count(5) == 1);
    std::unordered_multimap<int, int> records = {{1, 10}, {1, 20}, {2, 30}};
    auto range = records.equal_range(1);
    int sum = 0;
    for (auto it = range.first; it != range.second; ++it) {
        sum += it->second;
    }
    assert(sum == 30);
    assert(records.erase(1) == 2);
    assert(records.size() == 1);
    std::cout << "checks passed\n";
}
