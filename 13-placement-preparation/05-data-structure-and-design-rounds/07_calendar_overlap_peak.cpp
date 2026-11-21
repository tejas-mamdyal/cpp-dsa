/*
 Half-open nonempty intervals.

All changes at the same coordinate are combined before measuring the next
interval.

At 2, one event ends and one starts, so active remains 2.

Between endpoints the active set is constant; net deltas compute exactly its
size.

O(n log n) time, O(n) event storage.

Separate start-before-end processing would incorrectly overlap touching half-open
events.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

int peak(const std::vector<std::pair<int, int>>& events) {
    std::map<int, int> change;
    for (auto [begin, end] : events) {
        ++change[begin];
        --change[end];
    }
    int active = 0;
    int best = 0;
    for (auto [time, delta] : change) {
        (void)time;
        active += delta;
        best = std::max(best, active);
    }
    return best;
}

int main() {
    assert(peak({{0, 2}, {2, 4}, {1, 3}}) == 2);
    assert(peak({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
