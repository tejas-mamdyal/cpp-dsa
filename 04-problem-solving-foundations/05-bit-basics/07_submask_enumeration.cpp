/*
ENUMERATE ONLY SUBSETS OF SELECTED BITS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mask in0..255; include submask0 exactly once. IDEA AND STATE: Repeatedly
use(submask-1)&mask and stop after0. TRACE: mask10 ->10,8,2,0. CORRECTNESS: Subtracting moves
to the next lower allowed combination after the AND clears forbidden bits. COST:
O(2^popcount(mask)) output/time,O(output) stored results. PITFALL: Without the zero break,
unsigned wrap restarts the enumeration forever. PRACTICE: Change the example, predict each
state update and add an empty/boundary case. No input unless explicitly stated. Assertions are
the teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<unsigned int> submasks(unsigned int mask) {
    std::vector<unsigned int> out;
    unsigned int sub = mask;
    while (true) {
        out.push_back(sub);
        if (sub == 0U) {
            break;
        }
        sub = (sub - 1U) & mask;
    }
    return out;
}

int main() {
    for (unsigned int mask = 0; mask < 256U; ++mask) {
        auto actual = submasks(mask);
        std::vector<unsigned int> expected;
        for (unsigned int candidate = 0; candidate < 256U; ++candidate) {
            if ((candidate | mask) == mask) {
                expected.push_back(candidate);
            }
        }
        std::sort(actual.begin(), actual.end());
        assert(actual == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
