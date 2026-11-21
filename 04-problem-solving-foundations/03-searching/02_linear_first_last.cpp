/*
LINEAR FIRST AND LAST MATCHING POSITIONS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Any int vector; return a pair of first/last indices or{-1,-1}. IDEA AND STATE: Scan
once and preserve the first match while updating the latest match. TRACE: 4,2,4,4 ->target4
positions0,3. CORRECTNESS: After each prefix first is earliest and last latest among matches
already processed. COST: O(n) time,O(1) extra space. PITFALL: Do not initialize absence to0, a
valid position. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

std::pair<int, int> positions(const std::vector<int>& a, int key) {
    int first = -1;
    int last = -1;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (a[i] == key) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    return {first, last};
}

int main() {
    assert((positions({4, 2, 4, 4}, 4) == std::pair<int, int>{0, 3}));
    assert((positions({}, 4) == std::pair<int, int>{-1, -1}));
    assert((positions({1}, 2) == std::pair<int, int>{-1, -1}));
    std::cout << "checks passed\n";
    return 0;
}
