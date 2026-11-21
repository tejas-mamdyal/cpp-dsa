/*
 Positions bounded 0..1000000, distinct;2<=cows<=n; invalid counts absent.

IDEA AND STATE: Sort positions and place the next cow as early as possible; use an upper
midpoint for the last true distance.

TRACE: 1,2,4,8,9 with 3 cows ->3.

Distance3 places at1,4,8;distance4 permits only1,8,so the last feasible distance is3.

Earliest placement cannot reduce later room; increasing requested separation
cannot create a feasible placement.

O(n log n+n log R) time, O(n) copied input.

A lower midpoint with low=mid can stall on two candidates.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> separation(std::vector<int> positions, int cows) {
    if (cows < 2 || cows > static_cast<int>(positions.size())) {
        return std::nullopt;
    }
    std::sort(positions.begin(), positions.end());
    int low = 0;
    int high = positions.back() - positions.front();
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        int used = 1;
        int last = positions[0];
        for (std::size_t i = 1; i < positions.size(); ++i) {
            if (positions[i] - last >= mid) {
                ++used;
                last = positions[i];
            }
        }
        if (used >= cows) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    assert(separation({1, 2, 4, 8, 9}, 3) == 3);
    assert(separation({0, 10}, 2) == 10);
    assert(!separation({1}, 2));
    std::cout << "checks passed\n";
    return 0;
}
