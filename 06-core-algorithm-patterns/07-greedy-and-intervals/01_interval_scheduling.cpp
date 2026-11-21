/*
 Nonempty half-open intervals[start, end); touching intervals are compatible.

IDEA AND STATE: Sort by finish and select the next compatible interval.

TRACE: [0,3),[1,2),[2,4) ->2.

Finishing at2 is earlier than3,so select[1,2),then[2,4);the long competing interval is
skipped.

Exchange the first optimum interval for the earliest-finishing choice; this leaves
at least as much room, then repeat on the suffix.

O(n log n) time, O(n) copied input plus sorting stack.

Earliest start or shortest duration has no equivalent exchange guarantee.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

struct Interval {
    int start;
    int end;
};

int schedule(std::vector<Interval> a) {
    std::sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) {
        return x.end < y.end;
    });
    int count = 0;
    std::optional<int> finish;
    for (const auto& x : a) {
        assert(x.start < x.end);
        if (!finish || x.start >= *finish) {
            ++count;
            finish = x.end;
        }
    }
    return count;
}

int main() {
    assert(schedule({{0, 3}, {1, 2}, {2, 4}}) == 2);
    assert(schedule({{0, 1}, {1, 2}}) == 2);
    assert(schedule({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
