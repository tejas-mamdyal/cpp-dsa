/*
ANAGRAM CHECKING WITH 26 COUNTERS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Compare lowercase-English strings by letter multiplicity. Inputs must contain only a..z.
Trace: silent and listen have identical letter counts.
Why it works: Incrementing for one string and decrementing for the other leaves all zeros exactly when multiplicities match.
Cost: O(n+26) time, O(26) space.
Common mistake: Validate/normalize the alphabet before using ch-a as an index; this helper has a lowercase-only precondition.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

bool anagram(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return false;
    }
    int count[26] = {};
    for (char ch : a) {
        ++count[ch - 'a'];
    }
    for (char ch : b) {
        --count[ch - 'a'];
    }
    for (int value : count) {
        if (value != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(anagram("silent", "listen"));
    assert(anagram("", ""));
    assert(!anagram("aab", "abb"));
    assert(!anagram("a", "aa"));
    std::cout << "checks passed\n";
}
