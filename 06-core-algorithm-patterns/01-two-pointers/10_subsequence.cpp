/*
 Decide whether needle is a subsequence of text; order matters but adjacency does not.

IDEA AND STATE: Scan text and advance the matched-prefix length only when the next needed
character appears.

TRACE: ace is a subsequence of abcde.

Match a,skip b,match c,skip d,match e;all three requested characters have been consumed.

The earliest possible match leaves at least as much suffix available as any later
match.

O(n+m) upper bound time, O(1) space.

A subsequence is not a contiguous substring.
*/
#include <iostream>
#include <cassert>
#include <string>

bool subsequence(const std::string& needle, const std::string& text) {
    std::size_t matched = 0;
    for (char ch : text) {
        if (matched < needle.size() && needle[matched] == ch) {
            ++matched;
        }
    }
    return matched == needle.size();
}

int main() {
    assert(subsequence("ace", "abcde"));
    assert(subsequence("", ""));
    assert(!subsequence("aec", "abcde"));
    assert(!subsequence("a", ""));
    std::cout << "checks passed\n";
    return 0;
}
