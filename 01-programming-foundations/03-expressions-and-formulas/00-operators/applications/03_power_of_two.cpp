/*
RECOGNIZE A POWER OF TWO
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Read a signed integer in [-1000000000,1000000000]. A positive power of two has exactly one set bit.
Trace: 16 & 15 is 0; 12 & 11 is 8; zero must be excluded.
Why it works: The loop invariant or arithmetic identity below preserves exactly the desired result.
Cost: O(1) time and space for a fixed-width integer.
Common mistake: Read the stated input bounds and multiplicity assumptions; the program is not a general solution outside them.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    long long value = 0;
    if (!(std::cin >> value) || value < -1000000000LL || value > 1000000000LL) {
        std::cerr << "Invalid number.\n";
        return 1;
    }
    bool answer = value > 0 && (value & (value - 1)) == 0;
    std::cout << answer << '\n';
}
