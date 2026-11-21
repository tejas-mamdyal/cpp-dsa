/*
 0<=k<=number of distinct words.

The comparator ranks the full requested tie policy.

i and love both occur twice; alphabetical order puts i first.

Sorting all distinct keys by the specification yields the top k prefix.

O(total text counting plus u log u comparison work), O(total distinct text) storage.

A heap comparator must be reversed carefully if replacing this clear baseline.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstddef>

std::vector<std::string> frequent(const std::vector<std::string>& words, int k) {
    std::map<std::string, int> counts;
    for (auto& word : words) {
        ++counts[word];
    }
    std::vector<std::string> keys;
    for (auto& entry : counts) {
        keys.push_back(entry.first);
    }
    std::sort(keys.begin(), keys.end(), [&](const auto& a, const auto& b) {
        if (counts.at(a) != counts.at(b)) {
            return counts.at(a) > counts.at(b);
        }
        return a < b;
    });
    keys.resize(static_cast<std::size_t>(k));
    return keys;
}

int main() {
    assert((frequent({"i", "love", "code", "i", "love", "cpp"}, 2)
            == std::vector<std::string>{"i", "love"}));
    std::cout << "checks passed\n";
    return 0;
}
