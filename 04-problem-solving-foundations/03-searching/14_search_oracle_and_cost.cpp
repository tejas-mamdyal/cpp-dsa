/*
EXHAUST SEARCH BOUNDARIES AGAINST A LINEAR ORACLE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Enumerate all nondecreasing vectors of length0..5 over{0,1,2};compare own lower
boundary with linear scanning. IDEA AND STATE: Decode base3, sort and compare for
targets-1..3. TRACE: Empty gives0;[0,1,1],key1 gives1. CORRECTNESS: A direct scan
independently identifies the first not-less element; exhaustive inputs exercise duplicates and
end boundaries. COST: Helper O(log n) time/O(1) space; bounded oracle harness enumerates364
raw vectors and5 targets. PITFALL: The oracle is evidence on a finite domain, not a proof
outside it. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::size_t lower(const std::vector<int>& a, int key) {
    std::size_t l = 0;
    std::size_t r = a.size();
    while (l < r) {
        std::size_t m = l + (r - l) / 2;
        if (a[m] < key) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    int checked = 0;
    for (int n = 0; n <= 5; ++n) {
        int total = 1;
        for (int i = 0; i < n; ++i) {
            total *= 3;
        }
        for (int code = 0; code < total; ++code) {
            int x = code;
            std::vector<int> a(static_cast<std::size_t>(n));
            for (int& value : a) {
                value = x % 3;
                x /= 3;
            }
            std::sort(a.begin(), a.end());
            for (int key = -1; key <= 3; ++key) {
                std::size_t expected = 0;
                while (expected < a.size() && a[expected] < key) {
                    ++expected;
                }
                assert(lower(a, key) == expected);
                ++checked;
            }
        }
    }
    assert(checked == 1820);
    std::cout << "checks passed\n";
    return 0;
}
