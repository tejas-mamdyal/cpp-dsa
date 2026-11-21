/*
MERGE TWO ALREADY SORTED VECTORS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Advance the smaller head and append the unconsumed suffix. Inputs must be nondecreasing.
Trace: 1,3 plus2,3 ->1,2,3,3.
Why it works: The smallest remaining element is always one of the two current heads.
Cost: O(n+m) time and O(n+m) output storage.
Common mistake: This is a traversal exercise, not a general sorting algorithm; unsorted input violates its contract.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> merge(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    std::size_t i = 0;
    std::size_t j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            ++i;
        } else {
            result.push_back(b[j]);
            ++j;
        }
    }
    while (i < a.size()) {
        result.push_back(a[i]);
        ++i;
    }
    while (j < b.size()) {
        result.push_back(b[j]);
        ++j;
    }
    return result;
}

int main() {
    assert((merge({1, 3}, {2, 3}) == std::vector<int>{1, 2, 3, 3}));
    assert((merge({}, {2}) == std::vector<int>{2}));
    assert(merge({}, {}).empty());
    std::cout << "checks passed\n";
}
