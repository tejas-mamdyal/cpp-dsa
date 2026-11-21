/*
USE THE PERIOD-FOUR XOR IDENTITY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Endpoints0<=left<=right<=1000000000. IDEA AND STATE: XOR1..n repeats a four-case
pattern; cancel the prefix before left. TRACE: XOR3..6 =3^4^5^6=4. CORRECTNESS: XOR pairs
cancel and four consecutive aligned values establish the period. COST: O(1) fixed-width
time/space. PITFALL: Handle left0 before subtracting1 from an unsigned value. PRACTICE: Change
the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>

unsigned int prefix(unsigned int n) {
    switch (n % 4U) {
        case 0:
            return n;
        case 1:
            return 1U;
        case 2:
            return n + 1U;
        default:
            return 0U;
    }
}

unsigned int rangeXor(unsigned int left, unsigned int right) {
    if (left == 0U) {
        return prefix(right);
    }
    return prefix(right) ^ prefix(left - 1U);
}

int main() {
    unsigned int expected = 0;
    for (unsigned int n = 0; n <= 1000U; ++n) {
        expected ^= n;
        assert(prefix(n) == expected);
    }
    assert(rangeXor(3U, 6U) == 4U);
    assert(rangeXor(0U, 0U) == 0U);
    assert(rangeXor(7U, 7U) == 7U);
    std::cout << "checks passed\n";
    return 0;
}
