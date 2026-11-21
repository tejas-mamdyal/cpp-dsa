/*
REMOVE AND UNIQUE RETURN A LOGICAL END
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use erase-remove for filtering; sorted unique collapses adjacent equal values then erase changes size.
Trace: 1,2,2,3,4 remove evens ->1,3;1,1,2 unique ->1,2.
Why it works: Algorithms compact retained elements to a prefix; erase discards the unused suffix.
Cost: O(n) time and O(1) extra sequence storage.
Common mistake: remove/unique alone do not reduce container size, and unique removes adjacent duplicates only.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> values = {1, 2, 2, 3, 4};
    values.erase(std::remove_if(values.begin(),
                                values.end(),
                                [](int value) {
                                    return value % 2 == 0;
                                }),
                 values.end());
    assert((values == std::vector<int>{1, 3}));
    std::vector<int> duplicates = {1, 1, 2};
    duplicates.erase(std::unique(duplicates.begin(), duplicates.end()), duplicates.end());
    assert((duplicates == std::vector<int>{1, 2}));
    std::cout << "checks passed\n";
}
