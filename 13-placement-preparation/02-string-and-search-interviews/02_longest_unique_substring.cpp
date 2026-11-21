/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

[left, i] has no duplicate; last stores the latest position of each byte.

In abba, the final a must not move left backward.

The new left excludes the only newly conflicting occurrence while retaining the
longest valid ending suffix.

O(n log alphabet) time, O(alphabet) storage.

Assigning left=last+1 without max can reintroduce duplicates.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <map>

int uniqueLength(const std::string& s) {
    std::map<char, int> last;
    int left = 0;
    int best = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        auto found = last.find(s[i]);
        if (found != last.end()) {
            left = std::max(left, found->second + 1);
        }
        last[s[i]] = i;
        best = std::max(best, i - left + 1);
    }
    return best;
}

int main() {
    assert(uniqueLength("abba") == 2 && uniqueLength("") == 0 && uniqueLength("abcabcbb") == 3);
    std::cout << "checks passed\n";
    return 0;
}
