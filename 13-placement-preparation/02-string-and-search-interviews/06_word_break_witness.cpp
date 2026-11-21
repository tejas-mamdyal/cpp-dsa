/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

previous[end] records a reachable earlier prefix and the final dictionary
word.

leet reaches 4; code extends 4 to 8.

Every chosen predecessor has a valid decomposition and adds one nonempty word;
every possible final word is considered.

O(n^3 log(dictionary size+1)) conservative string-creation/comparison time, O(n) states
plus witness.

A true/false answer alone does not validate the reconstructed words.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <optional>
#include <set>

std::optional<std::vector<std::string>> split(const std::string& s,
                                              const std::set<std::string>& dictionary) {
    int n = static_cast<int>(s.size());
    std::vector<int> previous(n + 1, -1);
    previous[0] = 0;
    for (int end = 1; end <= n; ++end) {
        for (int begin = 0; begin < end; ++begin) {
            if (previous[begin] != -1 && dictionary.count(s.substr(begin, end - begin))) {
                previous[end] = begin;
                break;
            }
        }
    }
    if (previous[n] == -1) {
        return std::nullopt;
    }
    std::vector<std::string> out;
    for (int end = n; end > 0; end = previous[end]) {
        out.push_back(s.substr(previous[end], end - previous[end]));
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    auto out = split("leetcode", {"leet", "code"});
    assert(out && out->size() == 2);
    assert(!split("cats", {"cat"}));
    assert(split("", {})->empty());
    std::cout << "checks passed\n";
    return 0;
}
