/*
RECOVER AFTER FAILED FORMATTED INPUT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: clear resets failure state, ignore discards the malformed line, then extraction can resume.
Trace: oops then42: first extraction fails, recovered extraction succeeds.
Why it works: Both failure flags and offending characters must be handled before retrying.
Cost: O(L) time to skip a malformed line of L characters; O(1) extra space.
Common mistake: clear alone leaves the same bad text waiting and can create an infinite retry loop.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

int main() {
    std::istringstream input("oops\n42\n");
    int value = 0;
    assert(!(input >> value));
    input.clear();
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    assert(input >> value);
    assert(value == 42);
    std::cout << "checks passed\n";
}
