/*
 Sorted pairwise disjoint closed intervals; one valid new interval.

IDEA AND STATE: Copy strictly before, merge all touching/overlapping intervals, then copy
strictly after.

TRACE: [1,2],[5,7] inserting[2,6] ->[1,7].

Copy nothing before inserted[2,6] because[1,2] touches it;merging both existing intervals
produces[1,7].

Sorted disjoint components before and after the merge cannot interact with the
inserted union.

O(n) time, O(n) output.

The linear bound relies on pre-sorted merged input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
};

std::vector<Interval> insert(const std::vector<Interval>& a, Interval x) {
    std::vector<Interval> out;
    std::size_t i = 0;
    while (i < a.size() && a[i].end < x.start) {
        out.push_back(a[i]);
        ++i;
    }
    while (i < a.size() && a[i].start <= x.end) {
        x.start = std::min(x.start, a[i].start);
        x.end = std::max(x.end, a[i].end);
        ++i;
    }
    out.push_back(x);
    while (i < a.size()) {
        out.push_back(a[i]);
        ++i;
    }
    return out;
}

int main() {
    auto x = insert({{1, 2}, {5, 7}}, {2, 6});
    assert(x.size() == 1 && x[0].start == 1 && x[0].end == 7);
    assert(insert({}, {2, 2}).size() == 1);
    assert(insert({{1, 2}}, {5, 6}).size() == 2);
    std::cout << "checks passed\n";
    return 0;
}
