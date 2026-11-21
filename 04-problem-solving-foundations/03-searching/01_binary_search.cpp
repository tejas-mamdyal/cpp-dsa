/*
ITERATIVE EXACT BINARY SEARCH PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Nondecreasing int vector; length fits int; return any matching index or-1. IDEA AND
STATE: Maintain inclusive candidate interval[left,right]. TRACE: 1,3,5,7 target5:middle1
rejected, then middle2 matches. CORRECTNESS: Discarded halves cannot contain the key by sorted
order; every failed step shortens the interval. COST: O(log(n+1)) time,O(1) extra space.
PITFALL: An exact match is not necessarily the first duplicate; never binary-search unsorted
input. PRACTICE: Change the example, predict each state update and add an empty/boundary case.
No input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int search(const std::vector<int>& a, int key) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (a[middle] == key) {
            return middle;
        }
        if (a[middle] < key) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    assert(search({}, 4) == -1);
    assert(search({7}, 7) == 0);
    assert(search({7}, 6) == -1);
    std::vector<int> a = {-3, 0, 0, 2, 9};
    for (int key = -5; key <= 11; ++key) {
        int index = search(a, key);
        assert((index != -1) == std::binary_search(a.begin(), a.end(), key));
        if (index != -1) {
            assert(a[index] == key);
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
