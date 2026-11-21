/*
REVERSE WORD ORDER BY REVERSING TWICE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Words separated by exactly one ordinary space, no leading/trailing spaces; empty
allowed. IDEA AND STATE: Reverse all characters, then reverse each word. TRACE: one two ->owt
eno ->two one. CORRECTNESS: The global reversal exchanges word positions; local reversals
restore their spelling. COST: O(n) time,O(1) extra space. PITFALL: This contract does not
normalize repeated whitespace. PRACTICE: Change the example, predict each state update and add
an empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstddef>

void reverseWords(std::string& text) {
    std::reverse(text.begin(), text.end());
    std::size_t start = 0;
    while (start < text.size()) {
        std::size_t end = start;
        while (end < text.size() && text[end] != ' ') {
            ++end;
        }
        std::reverse(text.begin() + static_cast<std::ptrdiff_t>(start),
                     text.begin() + static_cast<std::ptrdiff_t>(end));
        start = end + 1;
    }
}

int main() {
    std::string a = "one two three";
    reverseWords(a);
    assert(a == "three two one");
    std::string empty;
    reverseWords(empty);
    assert(empty.empty());
    std::string one = "one";
    reverseWords(one);
    assert(one == "one");
    std::cout << "checks passed\n";
    return 0;
}
