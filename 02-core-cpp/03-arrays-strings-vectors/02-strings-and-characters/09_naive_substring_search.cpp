/*
FIND EVERY SUBSTRING OCCURRENCE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Return an occurrence count including overlaps; the empty pattern matches at n+1 boundaries.
Trace: aaaa contains aa at positions 0,1,2.
Why it works: Every legal start is checked character by character, and advancing by one retains overlaps.
Cost: O(n*m) time for text n and pattern m; O(1) extra space.
Common mistake: Check empty input and bounds before indexing; valid indices end at size()-1.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

std::size_t occurrences(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) {
        return text.size() + 1;
    }
    std::size_t count = 0;
    for (std::size_t start = 0; start + pattern.size() <= text.size(); ++start) {
        std::size_t matched = 0;
        while (matched < pattern.size() && text[start + matched] == pattern[matched]) {
            ++matched;
        }
        if (matched == pattern.size()) {
            ++count;
        }
    }
    return count;
}

int main() {
    assert(occurrences("aaaa", "aa") == 3);
    assert(occurrences("abc", "") == 4);
    assert(occurrences("a", "ab") == 0);
    std::cout << "checks passed\n";
}
