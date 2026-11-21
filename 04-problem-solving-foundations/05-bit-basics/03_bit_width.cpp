/*
COUNT SIGNIFICANT BITS AND FIND THE HIGHEST SET BIT PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Unsigned values; zero has width0 and no highest-set-bit index. IDEA AND STATE: Shift
until0, counting positions. TRACE: 8 is1000,width4,highest index3. CORRECTNESS: Each shift
removes one low-order bit until all significant positions are consumed. COST: O(width)
time,O(1) space. PITFALL: Width is not population count:8 has one set bit but four significant
positions. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <optional>

int width(unsigned int value) {
    int bits = 0;
    while (value != 0U) {
        ++bits;
        value >>= 1;
    }
    return bits;
}

std::optional<int> highest(unsigned int value) {
    if (value == 0U) {
        return std::nullopt;
    }
    return width(value) - 1;
}

int main() {
    assert(width(0U) == 0);
    assert(width(8U) == 4);
    assert(highest(8U) == 3);
    assert(!highest(0U));
    assert(width(7U) == 3);
    std::cout << "checks passed\n";
    return 0;
}
