/*
FIRST POSITION NOT LESS THAN A KEY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Sorted vector; return an insertion position in[0,size], including end. IDEA AND
STATE: Use half-open[left,right);a[middle]<key eliminates the left prefix. TRACE: 1,2,2,5 key2
->1; key6 ->4. CORRECTNESS: All indices before left are less than key; all at/after right are
not less. COST: O(log(n+1)) time,O(1) space. PITFALL: The returned end position is not a
dereferenceable match. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::size_t lower(const std::vector<int>& a, int key) {
    std::size_t left = 0;
    std::size_t right = a.size();
    while (left < right) {
        std::size_t middle = left + (right - left) / 2;
        if (a[middle] < key) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

int main() {
    std::vector<int> a = {1, 2, 2, 5};
    for (int key = -1; key <= 7; ++key) {
        assert(lower(a, key)
               == static_cast<std::size_t>(std::lower_bound(a.begin(), a.end(), key) - a.begin()));
    }
    assert(lower({}, 4) == 0);
    std::cout << "checks passed\n";
    return 0;
}
