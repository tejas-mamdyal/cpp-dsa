/*
 Exact byte text; return maximum length.

IDEA AND STATE: Store the most recent position and move left forward past a repeated byte.

TRACE: abcabcbb ->3; bbbbb ->1.

The second a repeats position0,so left becomes1;later repeats keep moving left and no valid
length exceeds3.

The retained interval contains no repeated byte; left never moves backward.

O(n+256) time, O(256) space.

An older repeated position before left must not move left backward.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <algorithm>

int longestUnique(const std::string& text) {
    std::array<int, 256> last;
    last.fill(-1);
    int left = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(text.size()); ++right) {
        unsigned char ch = static_cast<unsigned char>(text[right]);
        left = std::max(left, last[ch] + 1);
        last[ch] = right;
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    assert(longestUnique("abcabcbb") == 3);
    assert(longestUnique("abba") == 2);
    assert(longestUnique("bbbbb") == 1);
    assert(longestUnique("") == 0);
    std::cout << "checks passed\n";
    return 0;
}
