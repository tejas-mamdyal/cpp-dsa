/*
 Nonempty half-open meetings; end at t frees a room for start at t.

IDEA AND STATE: Sort events by time, then end(-1) before start(+1); track peak active.

TRACE: [0,10),[10,20) ->1 room.

At10,the ending meeting decreases active before the next start increases it;peak stays1.

Between consecutive event coordinates active meetings are constant; every meeting
needs a distinct room at peak, and freed rooms can always be reused.

O(n log n) time, O(n) event storage.

Tie order is part of the contract.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

int rooms(const std::vector<std::pair<int, int>>& meetings) {
    std::vector<std::pair<int, int>> events;
    for (auto x : meetings) {
        assert(x.first < x.second);
        events.emplace_back(x.first, 1);
        events.emplace_back(x.second, -1);
    }
    std::sort(events.begin(), events.end());
    int active = 0;
    int best = 0;
    for (auto event : events) {
        active += event.second;
        best = std::max(best, active);
    }
    return best;
}

int main() {
    assert(rooms({{0, 10}, {10, 20}}) == 1);
    assert(rooms({{0, 30}, {5, 10}, {15, 20}}) == 2);
    assert(rooms({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
