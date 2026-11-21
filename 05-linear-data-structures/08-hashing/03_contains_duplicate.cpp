/*
COMPARE HASHING WITH SORTING FOR DUPLICATE DETECTION PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Int vector; observation must leave caller input unchanged. IDEA AND STATE: Hash
inserts detect previous values; sorting a copy exposes adjacent equals. TRACE: 2,1,2
duplicates;2,1,3 does not. CORRECTNESS: Any repeated value creates either a repeated insertion
or an adjacent sorted pair. COST: Hash expected O(n),worst O(n^2),O(n) space; sorted copy O(n
log n),O(n) copy. PITFALL: Sorting caller data changes its order unless a copy is explicit.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_set>

bool hashDuplicate(const std::vector<int>& a) {
    std::unordered_set<int> seen;
    for (int value : a) {
        if (!seen.insert(value).second) {
            return true;
        }
    }
    return false;
}

bool sortDuplicate(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    return std::adjacent_find(a.begin(), a.end()) != a.end();
}

int main() {
    for (std::vector<int> a :
         std::vector<std::vector<int>>{{}, {1}, {2, 1, 2}, {2, 1, 3}, {-1, -1}}) {
        auto before = a;
        assert(hashDuplicate(a) == sortDuplicate(a));
        assert(a == before);
    }
    std::cout << "checks passed\n";
    return 0;
}
