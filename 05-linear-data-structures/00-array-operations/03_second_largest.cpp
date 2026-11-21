/*
DISTINCT SECOND MAXIMUM WITHOUT A SENTINEL PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Int vector; return optional second distinct maximum. IDEA AND STATE: Track the
maximum and an optional smaller runner-up. TRACE: 4,9,9,2 ->4;9,9 ->absence. CORRECTNESS:
After each element the state is the greatest and second-greatest distinct values seen. COST:
O(n) time,O(1) space. PITFALL: INT_MIN may be a valid value; do not use it to mean missing.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

std::optional<int> second(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    int largest = a[0];
    std::optional<int> runner;
    for (int value : a) {
        if (value > largest) {
            runner = largest;
            largest = value;
        } else if (value < largest && (!runner || value > *runner)) {
            runner = value;
        }
    }
    return runner;
}

int main() {
    assert(second({4, 9, 9, 2}) == 4);
    assert(second({-3, -9, -2}) == -3);
    assert(!second({9, 9}));
    assert(!second({}));
    std::cout << "checks passed\n";
    return 0;
}
