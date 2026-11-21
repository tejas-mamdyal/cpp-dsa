/*
 Closed intervals with start<=end; one point hits every interval containing it.

IDEA AND STATE: Sort by end; place an arrow there only if current interval starts after the
last arrow.

TRACE: [1,3],[2,4],[4,5] ->2 arrows.

Place first arrow at3 to hit[1,3] and[2,4];[4,5] needs a second arrow at5.

Any hit of the earliest-ending interval can move to its end without losing a
remaining interval it hit; repeat after removing covered intervals.

O(n log n) time, O(n) copied input.

At equal start and arrow coordinate, the closed interval is already hit.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>

int arrows(std::vector<std::pair<int, int>> a) {
    std::sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second < y.second;
    });
    std::optional<int> position;
    int count = 0;
    for (auto x : a) {
        assert(x.first <= x.second);
        if (!position || x.first > *position) {
            position = x.second;
            ++count;
        }
    }
    return count;
}

int main() {
    assert(arrows({{1, 3}, {2, 4}, {4, 5}}) == 2);
    assert(arrows({{1, 2}, {2, 3}}) == 1);
    assert(arrows({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
