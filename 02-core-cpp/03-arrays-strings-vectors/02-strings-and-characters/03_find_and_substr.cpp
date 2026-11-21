/*
SEARCH STRINGS WITHOUT CONFUSING NPOS AND ZERO
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: find returns an index or npos; substr copies a selected segment.
Trace: banana.find(ana)=1; the next match starts at 3.
Why it works: Starting the second search one character later permits overlapping matches.
Cost: find can take O(n*m) comparisons for pattern length m; substr copies O(k) characters.
Common mistake: npos is an unsigned sentinel; test equality with npos before adding or indexing.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

int main() {
    std::string text = "banana";
    std::size_t first = text.find("ana");
    assert(first == 1);
    assert(text.find("ana", first + 1) == 3);
    assert(text.find("xyz") == std::string::npos);
    assert(text.substr(1, 3) == "ana");
    assert(text.substr(text.size()).empty());
    std::cout << "checks passed\n";
}
