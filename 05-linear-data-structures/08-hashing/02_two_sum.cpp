/*
TWO-SUM INDICES REQUIRE A PREVIOUS OCCURRENCE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Values/target bounded to magnitude1000000; length fits int. IDEA AND STATE: Look up
the complement before inserting the current index. TRACE: 3,3 target6 uses two different
indices. CORRECTNESS: The table contains only earlier indices, so a found complement cannot
reuse the current element. COST: Expected O(n) time,O(n) space; O(n^2) worst hashing. PITFALL:
Inserting before lookup can falsely use one value twice. PRACTICE: Change the example, predict
each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <optional>
#include <utility>

std::optional<std::pair<int, int>> twoSum(const std::vector<int>& a, int target) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        auto it = seen.find(target - a[i]);
        if (it != seen.end()) {
            return std::pair<int, int>{it->second, i};
        }
        seen.emplace(a[i], i);
    }
    return std::nullopt;
}

int main() {
    assert((twoSum({2, 7, 11}, 9) == std::optional<std::pair<int, int>>{{0, 1}}));
    assert(twoSum({3, 3}, 6));
    assert(!twoSum({3}, 6));
    assert(!twoSum({}, 0));
    std::cout << "checks passed\n";
    return 0;
}
