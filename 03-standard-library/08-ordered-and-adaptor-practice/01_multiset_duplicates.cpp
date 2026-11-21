/*
MULTISET STORES DUPLICATE SORTED VALUES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Compare erase(iterator) of one occurrence with erase(value) of every equal occurrence.
Trace: 2,2,3 erase one2 ->2,3; erase value2 removes the remaining one.
Why it works: The selected iterator denotes a single node, while key erasure selects an equal-key range.
Cost: O(log n) search/insertion; erase(key) O(log n + removed count).
Common mistake: erase(end()) is invalid. set would discard duplicate keys.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <set>

int main() {
    std::multiset<int> values = {2, 2, 3};
    assert(values.count(2) == 2);
    auto it = values.find(2);
    assert(it != values.end());
    values.erase(it);
    assert(values.count(2) == 1);
    assert(values.erase(2) == 1);
    assert(values.count(2) == 0);
    std::cout << "checks passed\n";
}
