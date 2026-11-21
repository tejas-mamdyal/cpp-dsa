/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

Sorted character sequences are canonical multiset keys.

eat, tea, ate all map to aet.

Equal signatures are equivalent to equal character multiplicities.

O(total sorting work plus map lookup), O(total text) storage.

A set of characters would lose multiplicity.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

std::vector<std::vector<std::string>> groups(const std::vector<std::string>& words) {
    std::map<std::string, std::vector<std::string>> bins;
    for (auto word : words) {
        auto key = word;
        std::sort(key.begin(), key.end());
        bins[key].push_back(word);
    }
    std::vector<std::vector<std::string>> out;
    for (auto& entry : bins) {
        out.push_back(entry.second);
    }
    return out;
}

int main() {
    auto out = groups({"eat", "tea", "bat", "ate"});
    assert(out.size() == 2 && out[1].size() == 3);
    assert(groups({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
