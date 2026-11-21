/*
 Closed intervals[start, end], including points; touching endpoints merge.

IDEA AND STATE: Keep one unfinished merged interval; extend its end or start a separate
interval.

TRACE: [1,3],[3,5],[8,9] ->[1,5],[8,9].

After sorting,[1,3] absorbs[3,5] into[1,5];the gap before8 starts a new component.

Sorted future starts cannot fill a gap already passed; overlap extends only the
current union component.

O(n log n) time, O(n) output and copied input.

Closed endpoint semantics differ from the earlier half-open scheduling lessons.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
};

std::vector<Interval> merge(std::vector<Interval> a) {
    std::sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) {
        return x.start < y.start;
    });
    std::vector<Interval> out;
    for (const auto& x : a) {
        assert(x.start <= x.end);
        if (out.empty() || x.start > out.back().end) {
            out.push_back(x);
        } else {
            out.back().end = std::max(out.back().end, x.end);
        }
    }
    return out;
}

int main() {
    auto a = merge({{1, 3}, {3, 5}, {8, 9}});
    assert(a.size() == 2 && a[0].start == 1 && a[0].end == 5);
    assert(merge({}).empty());
    assert(merge({{2, 2}, {2, 2}}).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
