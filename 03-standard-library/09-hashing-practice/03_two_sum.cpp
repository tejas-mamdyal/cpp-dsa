/*
TWO SUM WITH ORIGINAL INDICES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Return two different indices whose bounded int values sum to a target. Look up the complement before inserting the current value.
Trace: 2,7,11 target9 -> indices0,1;3,3 target6 ->0,1.
Why it works: The map contains only earlier positions, so any found partner is a different element.
Cost: Expected O(n) time, worst O(n^2); O(n) space.
Common mistake: Inputs and target are within [-1000000,1000000] and length fits int. General int subtraction needs overflow care.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <optional>
#include <vector>
#include <utility>

std::optional<std::pair<int, int>> twoSum(const std::vector<int>& values, int target) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        auto found = seen.find(target - values[i]);
        if (found != seen.end()) {
            return std::pair<int, int>{found->second, i};
        }
        seen.emplace(values[i], i);
    }
    return std::nullopt;
}

int main() {
    auto first = twoSum({2, 7, 11}, 9);
    assert(first && first->first == 0 && first->second == 1);
    assert(twoSum({3, 3}, 6));
    assert(!twoSum({3}, 6));
    assert(!twoSum({}, 0));
    std::cout << "checks passed\n";
}
