/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

All columns before i match every word.

f and l match; the third column differs.

The first mismatching or missing character cannot belong to a common prefix.

O(total compared characters) time, O(prefix) output.

Check the shorter-word boundary before indexing.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

std::string common(const std::vector<std::string>& words) {
    if (words.empty()) {
        return "";
    }
    for (std::size_t i = 0; i < words[0].size(); ++i) {
        for (const auto& word : words) {
            if (i == word.size() || word[i] != words[0][i]) {
                return words[0].substr(0, i);
            }
        }
    }
    return words[0];
}

int main() {
    assert(common({"flower", "flow", "flight"}) == "fl");
    assert(common({}).empty());
    assert(common({"a", ""}).empty());
    std::cout << "checks passed\n";
    return 0;
}
