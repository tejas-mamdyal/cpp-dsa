/*
 Nonempty half-open intervals; minimum removals to leave compatible intervals.

IDEA AND STATE: Subtract the maximum kept schedule from n.

TRACE: [1,2),[2,3),[1,3) ->1 removal.

The maximum schedule keeps[1,2) and[2,3);three originals minus two kept gives one removal.

Every valid removal set leaves a schedule and vice versa; maximizing kept items
minimizes removed ones.

O(n log n) time, O(n) copied storage.

This counts interval deletions, not the amount of overlap.
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

int removals(const std::vector<Interval>& a) {
    return static_cast<int>(a.size()) - schedule(a);
}

int main() {
    assert(removals({{1, 2}, {2, 3}, {1, 3}}) == 1);
    assert(removals({}) == 0);
    assert(removals({{1, 3}, {1, 3}}) == 1);
    std::cout << "checks passed\n";
    return 0;
}
