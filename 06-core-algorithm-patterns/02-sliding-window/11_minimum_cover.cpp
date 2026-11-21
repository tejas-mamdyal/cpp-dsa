/*
 Return an earliest shortest substring covering pattern multiplicities; absence if
impossible, empty string for empty pattern.

IDEA AND STATE: Track how many required byte types meet their count, then shrink while all are
satisfied.

TRACE: ADOBECODEBANC covering ABC ->BANC.

ADOBEC first covers all categories;shrinking removes redundant characters;later BANC improves
the best length to4.

Every valid endpoint is minimized by removing surplus left characters; the best
across endpoints is globally shortest.

O(n+m+256) time, O(256) working space plus returned text.

Coverage needs multiplicities, not just membership; empty cover differs from absence.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <optional>

std::optional<std::string> minimumCover(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) {
        return std::string{};
    }
    std::array<int, 256> need{};
    std::array<int, 256> have{};
    int required = 0;
    for (unsigned char ch : pattern) {
        if (need[ch] == 0) {
            ++required;
        }
        ++need[ch];
    }
    int formed = 0;
    std::size_t left = 0;
    std::size_t best = text.size() + 1;
    std::size_t start = 0;
    for (std::size_t right = 0; right < text.size(); ++right) {
        unsigned char ch = static_cast<unsigned char>(text[right]);
        ++have[ch];
        if (need[ch] > 0 && have[ch] == need[ch]) {
            ++formed;
        }
        while (formed == required) {
            if (right - left + 1 < best) {
                best = right - left + 1;
                start = left;
            }
            unsigned char old = static_cast<unsigned char>(text[left]);
            ++left;
            if (need[old] > 0 && have[old] == need[old]) {
                --formed;
            }
            --have[old];
        }
    }
    if (best > text.size()) {
        return std::nullopt;
    }
    return text.substr(start, best);
}

int main() {
    assert(minimumCover("ADOBECODEBANC", "ABC") == "BANC");
    assert(minimumCover("AAAB", "AAB") == "AAB");
    assert(!minimumCover("a", "aa"));
    assert(minimumCover("abc", "") == "");
    std::cout << "checks passed\n";
    return 0;
}
