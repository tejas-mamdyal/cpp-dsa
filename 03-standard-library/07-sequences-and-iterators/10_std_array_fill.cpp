/*
STANDARD ARRAY PRESERVES ITS EXTENT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: std::array<int,3> owns three contiguous ints and supports fill and checked access.
Trace: fill7 produces7,7,7; at1 becomes9.
Why it works: Unlike an adjusted raw array parameter, std::array retains its extent in its type.
Cost: O(n) fill and storage; O(1) indexed access.
Common mistake: at throws for an invalid index; std::array<int,0> is legal but has no front/back element.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <array>

int main() {
    std::array<int, 3> values{};
    assert(values[0] == 0);
    values.fill(7);
    values.at(1) = 9;
    assert(values.front() == 7 && values.back() == 7);
    assert(values[1] == 9);
    std::array<int, 0> empty{};
    assert(empty.empty());
    std::cout << "checks passed\n";
}
