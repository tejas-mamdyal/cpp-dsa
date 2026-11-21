/*
MISSING-FILE HANDLING IS A NORMAL BRANCH
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Try to open a deliberately absent file in a fresh scratch directory.
Trace: open fails; fail state is true; no record is read.
Why it works: A failed open sets stream failure instead of creating input data.
Cost: One open attempt; operating-system cost is implementation-dependent.
Common mistake: Do not loop on !eof(); check whether the read operation succeeded. The checker provides an isolated scratch directory.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <fstream>

int main() {
    std::ifstream input("build/definitely_absent_for_lesson.txt");
    assert(!input.is_open());
    assert(input.fail());
    std::cout << "checks passed\n";
}
