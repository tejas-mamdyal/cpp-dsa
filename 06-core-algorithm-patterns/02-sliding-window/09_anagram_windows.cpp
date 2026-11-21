/*
 Lowercase English text/pattern; empty pattern returns no matches.

IDEA AND STATE: Compare 26 counts for each complete window of pattern length.

TRACE: cbaebabacd with abc ->starts 0,6.

The first three counts equal abc at start0;rolling one byte at a time finds equality again at
start6.

Equal frequency vectors exactly characterize anagrams over this alphabet.

O(26*n) time, O(26) working space plus output.

A set loses multiplicity; all strings obey the stated lowercase alphabet.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <vector>

std::vector<int> anagrams(const std::string& text, const std::string& pattern) {
    std::vector<int> result;
    if (pattern.empty() || pattern.size() > text.size()) {
        return result;
    }
    std::array<int, 26> need{};
    std::array<int, 26> have{};
    for (char ch : pattern) {
        ++need[ch - 'a'];
    }
    for (std::size_t right = 0; right < text.size(); ++right) {
        ++have[text[right] - 'a'];
        if (right >= pattern.size()) {
            --have[text[right - pattern.size()] - 'a'];
        }
        if (right + 1 >= pattern.size() && have == need) {
            result.push_back(static_cast<int>(right + 1 - pattern.size()));
        }
    }
    return result;
}

int main() {
    assert((anagrams("cbaebabacd", "abc") == std::vector<int>{0, 6}));
    assert((anagrams("abab", "ab") == std::vector<int>{0, 1, 2}));
    assert(anagrams("a", "").empty());
    assert(anagrams("a", "aa").empty());
    std::cout << "checks passed\n";
    return 0;
}
