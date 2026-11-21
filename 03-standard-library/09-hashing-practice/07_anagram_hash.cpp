/*
ANAGRAMS OVER CHARACTER BYTES WITH A HASH MAP
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Count byte multiplicities without assuming a lowercase alphabet. This is byte equality, not Unicode normalization.
Trace: Dorm and mroD have matching byte counts; Dorm and dorm do not.
Why it works: Every byte in the second string consumes one matching occurrence from the first.
Cost: Expected O(n) time, worst O(n*u); O(u) distinct byte keys.
Common mistake: Case folding, accents and Unicode code points require an explicit text policy beyond byte counting.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <string>

bool anagramBytes(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return false;
    }
    std::unordered_map<char, int> counts;
    for (char ch : a) {
        ++counts[ch];
    }
    for (char ch : b) {
        auto found = counts.find(ch);
        if (found == counts.end() || found->second == 0) {
            return false;
        }
        --found->second;
    }
    return true;
}

int main() {
    assert(anagramBytes("Dorm", "mroD"));
    assert(!anagramBytes("Dorm", "dorm"));
    assert(anagramBytes("", ""));
    std::cout << "checks passed\n";
}
