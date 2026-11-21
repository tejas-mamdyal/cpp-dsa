/*
FREQUENCY FIRST THEN ORIGINAL ORDER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Return the first input value appearing once, or absence. IDEA AND STATE: Count
globally then scan input order rather than hash iteration order. TRACE: 4,2,4,7 ->2.
CORRECTNESS: The second scan picks the earliest position whose completed count is1. COST:
Expected O(n) time,O(u) space; worst O(n*u) hash work. PITFALL: Unspecified hash traversal
cannot establish the first original occurrence. PRACTICE: Change the example, predict each
state update and add an empty/boundary case. No input unless explicitly stated. Assertions are
the teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <optional>

std::optional<int> firstUnique(const std::vector<int>& a) {
    std::unordered_map<int, int> counts;
    for (int value : a) {
        ++counts[value];
    }
    for (int value : a) {
        if (counts.at(value) == 1) {
            return value;
        }
    }
    return std::nullopt;
}

int main() {
    assert(firstUnique({4, 2, 4, 7}) == 2);
    assert(!firstUnique({1, 1}));
    assert(!firstUnique({}));
    assert(firstUnique({0}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
