/*
START CONSECUTIVE SCANS ONLY AT SEQUENCE BEGINNINGS PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Int values in[-1000000,1000000];duplicates ignored. IDEA AND STATE: A value without
predecessor starts a sequence; extend until the first absent successor. TRACE: 100,4,200,1,3,2
->length4 from1..4. CORRECTNESS: Every distinct value belongs to exactly one started run,
avoiding repeated full-run scans. COST: Expected O(n) time,O(u) space; O(n^2) worst hashing.
PITFALL: Bounds make value-1/current+1 representable; arbitrary INT_MIN/MAX would need guards.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_set>

int longest(const std::vector<int>& a) {
    std::unordered_set<int> values(a.begin(), a.end());
    int best = 0;
    for (int value : values) {
        if (values.count(value - 1) != 0) {
            continue;
        }
        int length = 1;
        int current = value;
        while (values.count(current + 1) != 0) {
            ++current;
            ++length;
        }
        best = std::max(best, length);
    }
    return best;
}

int main() {
    assert(longest({100, 4, 200, 1, 3, 2}) == 4);
    assert(longest({}) == 0);
    assert(longest({1, 1}) == 1);
    assert(longest({-2, -1, 0, 2}) == 3);
    std::cout << "checks passed\n";
    return 0;
}
