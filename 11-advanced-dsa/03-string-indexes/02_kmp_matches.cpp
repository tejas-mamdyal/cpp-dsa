/*
 Byte strings, length<=1000; empty pattern matches all text boundaries. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

j is the matched pattern-prefix length at the current text suffix; prefix
links preserve the next possible continuation after failure or complete match.

aa in aaa matches at 0, falls back to border length 1, then matches again at 1.

Skipped candidates fail their border requirement; all surviving alignments follow
the prefix chain without losing any match.

O(text+pattern+output) time, O(pattern) work plus output.

Resetting j to 0 after a match loses overlapping occurrences.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

std::vector<int> prefix(const std::string& p) {
    std::vector<int> pi(p.size());
    for (int i = 1; i < static_cast<int>(p.size()); ++i) {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

std::vector<int> matches(const std::string& text, const std::string& p) {
    std::vector<int> answer;
    if (p.empty()) {
        for (int i = 0; i <= static_cast<int>(text.size()); ++i) {
            answer.push_back(i);
        }
        return answer;
    }
    auto pi = prefix(p);
    int j = 0;
    for (int i = 0; i < static_cast<int>(text.size()); ++i) {
        while (j > 0 && text[i] != p[j]) {
            j = pi[j - 1];
        }
        if (text[i] == p[j]) {
            ++j;
        }
        if (j == static_cast<int>(p.size())) {
            answer.push_back(i - j + 1);
            j = pi[j - 1];
        }
    }
    return answer;
}

int main() {
    assert((matches("aaa", "aa") == std::vector<int>{0, 1}));
    assert((matches("abc", "") == std::vector<int>{0, 1, 2, 3}));
    assert(matches("abc", "z").empty());
    std::cout << "checks passed\n";
    return 0;
}
