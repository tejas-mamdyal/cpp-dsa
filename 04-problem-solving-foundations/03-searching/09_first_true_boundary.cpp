/*
SEARCH A MONOTONE PREDICATE BOUNDARY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Given n and firstTrue in[0,n], model a false prefix then true suffix; n means all
false. IDEA AND STATE: Binary search the predicate index>=firstTrue. TRACE: n8,boundary5 ->5;
all false ->8. CORRECTNESS: The false prefix and true suffix partition the candidate range;
every step preserves the first true position. COST: O(log(n+1)) predicate calls,O(1) space.
PITFALL: This applies only to monotone predicates. Binary search on numeric answers is
expanded in Phase4. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int firstTrueIndex(int n, int firstTrue) {
    int l = 0;
    int r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (m >= firstTrue) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    for (int n = 0; n <= 40; ++n) {
        for (int first = 0; first <= n; ++first) {
            assert(firstTrueIndex(n, first) == first);
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
