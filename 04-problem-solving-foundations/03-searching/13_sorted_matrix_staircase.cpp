/*
SEARCH ROWS AND COLUMNS SORTED INDEPENDENTLY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Rectangular matrix sorted nondecreasing in each row and column. IDEA AND STATE:
Start top-right; too large discards a column, too small discards a row. TRACE:
[1,4,7;2,5,8;3,6,9] target6:7->4->5->6. CORRECTNESS: The current corner bounds all values in
its row/column, so each discarded strip is impossible. COST: O(rows+columns) time,O(1) space.
PITFALL: This has a different precondition from row-major binary search; do not flatten this
matrix as sorted. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

bool staircase(const std::vector<std::vector<int>>& a, int key) {
    if (a.empty() || a[0].empty()) {
        return false;
    }
    int row = 0;
    int column = static_cast<int>(a[0].size()) - 1;
    while (row < static_cast<int>(a.size()) && column >= 0) {
        int value = a[row][column];
        if (value == key) {
            return true;
        }
        if (value > key) {
            --column;
        } else {
            ++row;
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<int>> a = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    for (int key = 0; key <= 10; ++key) {
        assert(staircase(a, key) == (key >= 1 && key <= 9));
    }
    assert(!staircase({}, 1));
    std::cout << "checks passed\n";
    return 0;
}
