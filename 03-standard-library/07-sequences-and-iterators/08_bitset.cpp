/*
FIXED-SIZE BIT SETS AND TEXTUAL BIT POSITIONS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use bitset<8> for eight flags with checked test/set/reset/flip and population count.
Trace: 00001010 ->set0 ->00001011 ->flip1 ->00001001.
Why it works: Each bit position is a boolean flag; transformations modify only the selected positions.
Cost: O(B) for whole-bitset operations on B bits in a portable upper bound; O(B) storage.
Common mistake: Position0 is the rightmost printed bit. Integer-to-bitset construction truncates high bits; out-of-range positional operations throw.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <bitset>

int main() {
    std::bitset<8> flags(10U);
    assert(flags.count() == 2);
    assert(flags.test(1));
    flags.set(0);
    flags.flip(1);
    assert(flags.to_string() == "00001001");
    flags.reset(3);
    assert(flags.to_ulong() == 1);
    assert(flags.any());
    flags.reset();
    assert(flags.none());
    flags.set();
    assert(flags.all());
    std::cout << "checks passed\n";
}
