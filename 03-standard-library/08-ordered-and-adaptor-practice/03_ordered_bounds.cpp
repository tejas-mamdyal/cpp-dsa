/*
ORDERED LOWER AND UPPER BOUNDS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use member lower_bound and upper_bound to locate >=key and >key.
Trace: set1,3,5: lower_bound3=3;upper_bound3=5.
Why it works: Tree ordering narrows the candidate range without linear stepping.
Cost: O(log n) per member search.
Common mistake: Prefer set/map member bounds; generic bounds on tree iterators may perform O(n) iterator steps.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <set>

int main() {
    std::set<int> values = {1, 3, 5};
    auto lower = values.lower_bound(3);
    auto upper = values.upper_bound(3);
    assert(lower != values.end() && *lower == 3);
    assert(upper != values.end() && *upper == 5);
    assert(values.lower_bound(6) == values.end());
    std::cout << "checks passed\n";
}
