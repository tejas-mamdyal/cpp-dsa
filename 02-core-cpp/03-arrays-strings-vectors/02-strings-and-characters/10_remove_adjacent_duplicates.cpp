/*
REMOVE REPEATED ADJACENT CHARACTERS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Keep a character only when it differs from the last retained character.
Trace: aaabbaa -> aba; separated occurrences are preserved.
Why it works: Exactly the first character of each adjacent run is retained.
Cost: O(n) time and O(n) output storage.
Common mistake: Check empty input and bounds before indexing; valid indices end at size()-1.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

std::string compress(const std::string& text) {
    std::string answer;
    for (char ch : text) {
        if (answer.empty() || answer.back() != ch) {
            answer.push_back(ch);
        }
    }
    return answer;
}

int main() {
    assert(compress("aaabbaa") == "aba");
    assert(compress("").empty());
    assert(compress("abc") == "abc");
    std::cout << "checks passed\n";
}
