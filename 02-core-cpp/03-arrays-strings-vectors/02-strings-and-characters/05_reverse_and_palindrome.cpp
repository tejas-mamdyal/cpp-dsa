/*
REVERSE AND CHECK A PALINDROME WITH INDICES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Copy characters in reverse order; compare symmetric positions. Case and spaces matter.
Trace: level equals its reverse; Level does not.
Why it works: Each pair of mirrored positions must match; half the positions cover all pairs.
Cost: O(n) time; reverse uses O(n) result storage, palindrome uses O(1) space.
Common mistake: Check empty input and bounds before indexing; valid indices end at size()-1.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

std::string reversed(const std::string& text) {
    std::string answer;
    for (std::size_t i = text.size(); i > 0; --i) {
        answer.push_back(text[i - 1]);
    }
    return answer;
}

bool palindrome(const std::string& text) {
    for (std::size_t i = 0; i < text.size() / 2; ++i) {
        if (text[i] != text[text.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(reversed("abc") == "cba");
    assert(reversed("").empty());
    assert(palindrome("level"));
    assert(palindrome(""));
    assert(!palindrome("Level"));
    std::cout << "checks passed\n";
}
