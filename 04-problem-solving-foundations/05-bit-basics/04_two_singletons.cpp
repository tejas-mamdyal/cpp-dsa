/*
TWO UNIQUE VALUES AMONG PAIRS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Unsigned values:exactly two distinct values occur once; every other value twice.
IDEA AND STATE: XOR all values, isolate one differing bit, then XOR the two groups. TRACE:
1,2,1,3,2,5 ->singletons3,5. CORRECTNESS: Pairs cancel within their bit group; the unique
values differ on the isolated bit and separate. COST: O(n) time,O(1) extra space. PITFALL: The
multiplicity condition is a precondition; XOR alone cannot validate it. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

std::pair<unsigned int, unsigned int> singles(const std::vector<unsigned int>& a) {
    unsigned int combined = 0;
    for (unsigned int value : a) {
        combined ^= value;
    }
    assert(combined != 0U);
    unsigned int mask = combined & (~combined + 1U);
    unsigned int first = 0;
    unsigned int second = 0;
    for (unsigned int value : a) {
        if ((value & mask) != 0U) {
            first ^= value;
        } else {
            second ^= value;
        }
    }
    if (first > second) {
        std::swap(first, second);
    }
    return {first, second};
}

int main() {
    assert((singles({1, 2, 1, 3, 2, 5}) == std::pair<unsigned int, unsigned int>{3, 5}));
    assert((singles({0, 7}) == std::pair<unsigned int, unsigned int>{0, 7}));
    std::cout << "checks passed\n";
    return 0;
}
