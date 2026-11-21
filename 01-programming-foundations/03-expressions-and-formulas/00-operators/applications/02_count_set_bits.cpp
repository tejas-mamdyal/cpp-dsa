/*
COUNT SET BITS BY REMOVING THE LOWEST ONE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Read an unsigned-sized value restricted to 0..1000000000 and count its set bits. Validate with signed long long before converting.
Trace: 12 (1100) -> 8 (1000) -> 0; two iterations.
Why it works: The loop invariant or arithmetic identity below preserves exactly the desired result.
Cost: O(k) time for k set bits, O(1) extra space.
Common mistake: Read the stated input bounds and multiplicity assumptions; the program is not a general solution outside them.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    long long input = 0;
    if (!(std::cin >> input) || input < 0 || input > 1000000000LL) {
        std::cerr << "Invalid number.\n";
        return 1;
    }
    unsigned int value = static_cast<unsigned int>(input);
    int count = 0;
    while (value != 0U) {
        value &= value - 1U;
        ++count;
    }
    std::cout << count << '\n';
}
