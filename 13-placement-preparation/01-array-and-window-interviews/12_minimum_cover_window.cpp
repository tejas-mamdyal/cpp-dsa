/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

need tracks deficits, negative counts are surplus; missing counts unmet
occurrences.

BANC covers one each of A, B, C in length 4.

Each valid window is shrunk until its first missing occurrence, so all minimal
ending windows are compared.

O(n log alphabet) time, O(alphabet) storage plus output.

Counting distinct required characters alone misses repeated target characters.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <map>
#include <cstddef>

std::string cover(const std::string& s, const std::string& target) {
    if (target.empty()) {
        return "";
    }
    std::map<char, int> need;
    for (char ch : target) {
        ++need[ch];
    }
    int missing = static_cast<int>(target.size());
    std::size_t left = 0;
    std::size_t best = s.size() + 1;
    std::size_t start = 0;
    for (std::size_t right = 0; right < s.size(); ++right) {
        if (need[s[right]]-- > 0) {
            --missing;
        }
        while (missing == 0) {
            if (right - left + 1 < best) {
                best = right - left + 1;
                start = left;
            }
            if (++need[s[left++]] > 0) {
                ++missing;
            }
        }
    }
    return best > s.size() ? "" : s.substr(start, best);
}

int main() {
    assert(cover("ADOBECODEBANC", "ABC") == "BANC");
    assert(cover("a", "aa").empty());
    assert(cover("abc", "").empty());
    std::cout << "checks passed\n";
    return 0;
}
