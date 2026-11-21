/*
 Half-open intervals with start<=end; bounded signed coordinates.

IDEA AND STATE: Aggregate starts/ends; when active>0 add the distance from the previous
coordinate.

TRACE: [1,4),[2,6),[8,9) ->6.

Coverage is active across1..6 for length5,zero across6..8,and active across8..9 for one
more,total6.

Active count is constant across each open gap between event coordinates; these
disjoint gaps partition the union length.

O(n log n) time, O(n) event space.

Count changes occur after measuring the preceding gap; zero-length intervals
contribute no measure.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <utility>

long long unionLength(const std::vector<std::pair<int, int>>& a) {
    std::map<int, int> events;
    for (auto x : a) {
        assert(x.first <= x.second);
        ++events[x.first];
        --events[x.second];
    }
    int active = 0;
    int previous = 0;
    long long total = 0;
    for (auto event : events) {
        if (active > 0) {
            total += 1LL * event.first - previous;
        }
        active += event.second;
        previous = event.first;
    }
    return total;
}

int main() {
    assert(unionLength({{1, 4}, {2, 6}, {8, 9}}) == 6);
    assert(unionLength({{2, 2}}) == 0);
    assert(unionLength({}) == 0);
    assert(unionLength({{-3, 0}, {0, 2}}) == 5);
    std::cout << "checks passed\n";
    return 0;
}
