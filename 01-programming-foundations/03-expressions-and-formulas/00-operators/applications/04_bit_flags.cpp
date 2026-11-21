/*
SET CLEAR TOGGLE AND TEST A BIT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Read value in 0..255 and position in 0..7. Print the value with that bit set, cleared, toggled, then its original bit state.
Trace: 10=1010 and position 1: set=10 clear=8 toggle=8 test=1.
Why it works: The loop invariant or arithmetic identity below preserves exactly the desired result.
Cost: O(1) time and space.
Common mistake: Read the stated input bounds and multiplicity assumptions; the program is not a general solution outside them.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int value = 0;
    int position = 0;
    if (!(std::cin >> value >> position) || value < 0 || value > 255 || position < 0
        || position > 7) {
        std::cerr << "Invalid flags.\n";
        return 1;
    }
    unsigned int bits = static_cast<unsigned int>(value);
    unsigned int mask = 1U << position;
    std::cout << (bits | mask) << ' ' << (bits & ~mask) << ' ' << (bits ^ mask) << ' '
              << ((bits & mask) != 0U) << '\n';
}
