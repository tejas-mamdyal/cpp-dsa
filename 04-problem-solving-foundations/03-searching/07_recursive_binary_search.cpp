/*
RECURSIVE BINARY SEARCH ON A HALF-OPEN RANGE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Sorted vector and valid[left,right);return index or-1. IDEA AND STATE: The base is
an empty range; each recursive call keeps only one half. TRACE: 1,4,7 target7
->[0,3),then[2,3) matches. CORRECTNESS: A sorted discarded half cannot contain the target;
interval length strictly decreases. COST: O(log(n+1)) time and call-stack space. PITFALL: Do
not copy the vector or omit the returned recursive result. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int findRange(const std::vector<int>& a, int key, std::size_t left, std::size_t right) {
    if (left == right) {
        return -1;
    }
    std::size_t middle = left + (right - left) / 2;
    if (a[middle] == key) {
        return static_cast<int>(middle);
    }
    if (a[middle] < key) {
        return findRange(a, key, middle + 1, right);
    }
    return findRange(a, key, left, middle);
}

int main() {
    std::vector<int> a = {1, 4, 7};
    for (int key = 0; key <= 8; ++key) {
        int index = findRange(a, key, 0, a.size());
        assert((index != -1) == std::binary_search(a.begin(), a.end(), key));
    }
    assert(findRange({}, 2, 0, 0) == -1);
    std::cout << "checks passed\n";
    return 0;
}
