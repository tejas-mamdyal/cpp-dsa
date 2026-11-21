/*
BINARY SEARCH A GLOBALLY ORDERED MATRIX PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Rectangular nonempty rows; each row sorted and each next row starts after the
previous last. Empty matrix is allowed. IDEA AND STATE: Map a virtual flat midpoint to
row=mid/columns,column=mid%columns. TRACE: [1,3,5;7,9,11] target9 maps flat4 to row1,column1.
CORRECTNESS: Global row-major ordering makes the virtual flattened sequence sorted. COST:
O(log(rows*columns+1)) time,O(1) space; matrix size must fit int here. PITFALL: Sorted rows
and columns alone do not guarantee this stronger global row-major condition. PRACTICE: Change
the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

bool matrixFind(const std::vector<std::vector<int>>& a, int key) {
    if (a.empty() || a[0].empty()) {
        return false;
    }
    int columns = static_cast<int>(a[0].size());
    int l = 0;
    int r = static_cast<int>(a.size()) * columns;
    while (l < r) {
        int m = l + (r - l) / 2;
        int value = a[m / columns][m % columns];
        if (value == key) {
            return true;
        }
        if (value < key) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return false;
}

int main() {
    assert(matrixFind({{1, 3, 5}, {7, 9, 11}}, 9));
    assert(!matrixFind({{1, 3, 5}, {7, 9, 11}}, 8));
    assert(!matrixFind({}, 1));
    assert(!matrixFind({{}}, 1));
    std::cout << "checks passed\n";
    return 0;
}
