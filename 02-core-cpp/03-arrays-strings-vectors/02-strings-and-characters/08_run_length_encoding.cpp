/*
RUN-LENGTH ENCODING PRESERVES GROUPS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Encode each maximal adjacent run as its character followed by its count.
Trace: aaabbc -> a3b2c1; the empty string stays empty.
Why it works: The inner loop ends at the first different character, so each input position belongs to exactly one emitted run.
Cost: O(n) time and O(n) output space.
Common mistake: This simple encoding is not unambiguous for digit-valued characters; decoding needs a specified alphabet or separators.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

std::string encode(const std::string& text) {
    std::string result;
    std::size_t i = 0;
    while (i < text.size()) {
        std::size_t end = i + 1;
        while (end < text.size() && text[end] == text[i]) {
            ++end;
        }
        result.push_back(text[i]);
        result += std::to_string(end - i);
        i = end;
    }
    return result;
}

int main() {
    assert(encode("aaabbc") == "a3b2c1");
    assert(encode("").empty());
    assert(encode("aaaaaaaaaaaa") == "a12");
    std::cout << "checks passed\n";
}
