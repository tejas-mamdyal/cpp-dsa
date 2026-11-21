/*
 k>=0; return longest length.

IDEA AND STATE: Remove zero-frequency entries so map.size equals distinct count.

TRACE: 1,2,1,2,3 with k 2 ->4.

The first four values use two keys and length4;adding3 forces shrinking until only2 and3
remain.

After shrinking, the retained suffix is the longest valid suffix for this
endpoint.

Expected O(n) time, O(k+1) map space; worst hashing can degrade.

A key left at frequency 0 would overstate distinct count.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>

int longestDistinct(const std::vector<int>& a, int k) {
    assert(k >= 0);
    std::unordered_map<int, int> counts;
    int left = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        ++counts[a[right]];
        while (static_cast<int>(counts.size()) > k) {
            int value = a[left];
            ++left;
            --counts[value];
            if (counts[value] == 0) {
                counts.erase(value);
            }
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    assert(longestDistinct({1, 2, 1, 2, 3}, 2) == 4);
    assert(longestDistinct({1, 1}, 0) == 0);
    assert(longestDistinct({}, 3) == 0);
    assert(longestDistinct({1, 2, 3}, 5) == 3);
    std::cout << "checks passed\n";
    return 0;
}
