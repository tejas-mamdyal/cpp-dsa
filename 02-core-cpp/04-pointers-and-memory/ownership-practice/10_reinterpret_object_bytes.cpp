/*
REINTERPRET CAST FOR OBJECT REPRESENTATION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Read an int representation through const unsigned char*. Never assume byte order or write an unrelated typed object.
Trace: sizeof(int) bytes can be visited; the value remains42.
Why it works: Character-byte types may inspect object representation; no unrelated typed dereference is performed.
Cost: O(sizeof(int)) time, O(1) space.
Common mistake: reinterpret_cast is not a numeric conversion and does not fix alignment, lifetime or aliasing violations. Prefer ordinary typed access.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int value = 42;
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&value);
    unsigned int checksum = 0;
    for (std::size_t i = 0; i < sizeof(value); ++i) {
        checksum += bytes[i];
    }
    (void)checksum;
    assert(value == 42);
    assert(sizeof(unsigned char) == 1);
    std::cout << "checks passed\n";
}
