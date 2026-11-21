/*
 Trips passengers>0, start<end on integer positions 0..20; occupancy uses[start, end).

IDEA AND STATE: Add at start, subtract at end, and scan combined event deltas.

TRACE: 2 passengers[1,5),3[3,7) exceed capacity 4.

Active passengers rise to2 at1 and5 at3;capacity4 is exceeded before a drop can occur.

At each position, the prefix of all event changes equals current onboard count.

O(trips+21) time, O(21) storage.

Half-open endpoints let a departing group free capacity for a group starting at the
same point.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <array>

struct Trip {
    int passengers;
    int start;
    int end;
};

bool carPool(const std::vector<Trip>& trips, int capacity) {
    assert(capacity >= 0);
    std::array<long long, 21> changes{};
    for (const Trip& trip : trips) {
        assert(trip.passengers > 0 && trip.start >= 0 && trip.start < trip.end && trip.end <= 20);
        changes[trip.start] += trip.passengers;
        changes[trip.end] -= trip.passengers;
    }
    long long used = 0;
    for (long long delta : changes) {
        used += delta;
        if (used > capacity) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(!carPool({{2, 1, 5}, {3, 3, 7}}, 4));
    assert(carPool({{2, 1, 3}, {2, 3, 5}}, 2));
    assert(carPool({}, 0));
    std::cout << "checks passed\n";
    return 0;
}
