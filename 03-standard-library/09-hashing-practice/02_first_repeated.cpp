/*
DETECT THE FIRST REPEATED ENCOUNTER
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Insert into an unordered_set and inspect insertion success.
Trace: 2,5,2,5 -> second2 is the earliest repeated encounter.
Why it works: Before each insertion the set contains exactly the previously seen values.
Cost: Expected O(n) time, worst O(n^2); O(u) space.
Common mistake: This asks for the first repeated encounter, not the smallest repeated value or earliest first occurrence.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <unordered_set>
#include <optional>
#include <vector>

std::optional<int> firstRepeated(const std::vector<int>& values) {
    std::unordered_set<int> seen;
    for (int value : values) {
        if (!seen.insert(value).second) {
            return value;
        }
    }
    return std::nullopt;
}

int main() {
    assert(firstRepeated({2, 5, 2, 5}).value() == 2);
    assert(!firstRepeated({1, 2, 3}));
    assert(!firstRepeated({}));
    std::cout << "checks passed\n";
}
