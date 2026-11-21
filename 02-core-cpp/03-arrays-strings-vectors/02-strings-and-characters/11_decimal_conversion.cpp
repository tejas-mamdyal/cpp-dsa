/*
CONVERT DECIMAL TEXT WITH BOUNDARY CHECKS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: stoi accepts a prefix, so inspect its consumed-length result; catch invalid_argument and out_of_range.
Trace: 42x parses a prefix of length 2, but strict conversion rejects it.
Why it works: The consumed count reveals unparsed suffix text; distinct exceptions separate syntax and range failures.
Cost: O(n) conversion time, implementation-dependent conversion storage.
Common mistake: This is a later bridge after pointers and exceptions; start with string streams in the parsing unit.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>

int main() {
    std::size_t consumed = 0;
    assert(std::stoi("-42", &consumed) == -42);
    assert(consumed == 3);
    assert(std::stoi("42x", &consumed) == 42);
    assert(consumed == 2);
    bool invalid = false;
    try {
        (void)std::stoi("words");
    } catch (const std::invalid_argument&) {
        invalid = true;
    }
    assert(invalid);
    bool overflow = false;
    try {
        (void)std::stoi("9999999999999999999999999");
    } catch (const std::out_of_range&) {
        overflow = true;
    }
    assert(overflow);
    std::cout << "checks passed\n";
}
