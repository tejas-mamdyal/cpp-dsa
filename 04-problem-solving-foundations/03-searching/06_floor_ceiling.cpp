/*
FLOOR AND CEILING WITH EXPLICIT ABSENCE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Sorted vector; return optional values floor<=key and ceiling>=key. IDEA AND STATE:
An insertion boundary identifies ceiling and its predecessor gives floor unless equality
holds. TRACE: 2,5,9 key6 ->5,9; key1 has no floor. CORRECTNESS: Sorted order makes adjacent
insertion neighbors the closest legal values. COST: O(log(n+1)) time,O(1) space. PITFALL: Use
optional rather than a sentinel that may be a valid input. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>

std::pair<std::optional<int>, std::optional<int>> neighbors(const std::vector<int>& a, int key) {
    auto it = std::lower_bound(a.begin(), a.end(), key);
    std::optional<int> floor;
    std::optional<int> ceiling;
    if (it != a.end()) {
        ceiling = *it;
        if (*it == key) {
            floor = *it;
        }
    }
    if (!floor && it != a.begin()) {
        floor = *(it - 1);
    }
    return {floor, ceiling};
}

int main() {
    auto p = neighbors({2, 5, 9}, 6);
    assert(p.first == 5 && p.second == 9);
    assert(!neighbors({2}, 1).first);
    assert(!neighbors({2}, 3).second);
    assert(!neighbors({}, 1).first);
    assert(neighbors({2, 2}, 2).first == 2);
    std::cout << "checks passed\n";
    return 0;
}
