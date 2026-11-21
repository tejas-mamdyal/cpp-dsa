/*
GROUP ANAGRAMS BY A CANONICAL SORTED KEY
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Sort a copy of each word and use it as an ordered-map key.
Trace: eat,tea,ate share key aet; bat has key abt.
Why it works: Two words have the same sorted key exactly when their byte multiplicities match.
Cost: O(sum m log m + total key-comparison costs) time for word lengths m; O(total characters) stored words/keys.
Common mistake: Sort a copy so the original spelling stays available; group ordering here follows map keys.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::map<std::string, std::vector<std::string>> groups;
    for (std::string word : {"eat", "tea", "bat", "ate"}) {
        std::string key = word;
        std::sort(key.begin(), key.end());
        groups[key].push_back(word);
    }
    assert(groups.size() == 2);
    assert(groups.at("aet").size() == 3);
    assert(groups.at("abt")[0] == "bat");
    std::cout << "checks passed\n";
}
