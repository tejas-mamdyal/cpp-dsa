/*
 Each arrival<=departure; at equal times arriving train requires a platform before a
departure frees one.

IDEA AND STATE: Sort arrivals as event 0 and departures as event 1, then update active count.

TRACE: [0,10],[10,20] ->2 platforms under this rule.

At10,the arrival is processed before departure,temporarily raising occupancy from1 to2.

Each event updates exactly the trains occupying platforms under the stipulated
tie policy; the peak is necessary and sufficient.

O(n log n) time, O(n) space.

Real systems may use another convention; state it rather than borrowing meeting-room
comparisons.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

int platforms(const std::vector<std::pair<int, int>>& trains) {
    std::vector<std::pair<int, int>> events;
    for (auto train : trains) {
        assert(train.first <= train.second);
        events.emplace_back(train.first, 0);
        events.emplace_back(train.second, 1);
    }
    std::sort(events.begin(), events.end());
    int active = 0;
    int best = 0;
    for (auto event : events) {
        active += event.second == 0 ? 1 : -1;
        best = std::max(best, active);
    }
    return best;
}

int main() {
    assert(platforms({{0, 10}, {10, 20}}) == 2);
    assert(platforms({{1, 1}}) == 1);
    assert(platforms({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
