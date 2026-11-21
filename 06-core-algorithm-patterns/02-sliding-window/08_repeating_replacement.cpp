/*
 Uppercase English text; k>=0 replacements.

IDEA AND STATE: Required edits equal window length minus its highest character frequency.
Recompute that maximum over 26 counters after shrinking.

TRACE: AABABBA with k 1 ->4.

At AABA,length4 minus highest count3 is1 and valid;adding more letters eventually requires
shrinking.

The window is valid exactly when enough copies of some one letter can fill it
using k edits.

O(26*n) time, O(26) space.

This version deliberately keeps an exact current maximum rather than relying on a
subtler stale-maximum proof.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <algorithm>

int replacements(const std::string& text, int k) {
    assert(k >= 0);
    std::array<int, 26> count{};
    int left = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(text.size()); ++right) {
        assert(text[right] >= 'A' && text[right] <= 'Z');
        ++count[text[right] - 'A'];
        while (right - left + 1 - *std::max_element(count.begin(), count.end()) > k) {
            --count[text[left] - 'A'];
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    assert(replacements("AABABBA", 1) == 4);
    assert(replacements("ABAB", 2) == 4);
    assert(replacements("", 0) == 0);
    assert(replacements("ABC", 0) == 1);
    std::cout << "checks passed\n";
    return 0;
}
