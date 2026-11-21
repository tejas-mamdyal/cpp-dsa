/*
FLOOR SQUARE ROOT WITHOUT MULTIPLICATION OVERFLOW PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 0<=x<=9223372036854775807; return greatest r with r*r<=x. IDEA AND STATE: Compare
middle<=x/middle, never middle*middle. TRACE: x26 ->5; x0 ->0. CORRECTNESS: The predicate is
true for all positive candidates up to the root and false afterward. COST: O(log(x+1))
time,O(1) space. PITFALL: Handle x<2 before division; cap the search to the largest possible
signed64-bit root. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long root(long long x) {
    if (x < 2) {
        return x;
    }
    long long l = 1;
    long long r = std::min(x, 3037000499LL);
    long long answer = 0;
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (m <= x / m) {
            answer = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return answer;
}

int main() {
    for (long long x = 0; x <= 1000; ++x) {
        long long r = root(x);
        assert(r * r <= x);
        assert((r + 1) * (r + 1) > x);
    }
    assert(root(9223372036854775807LL) == 3037000499LL);
    std::cout << "checks passed\n";
    return 0;
}
