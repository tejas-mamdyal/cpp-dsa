/*
ROTATE A SQUARE MATRIX WITHOUT A SECOND MATRIX PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Square matrix; empty allowed. IDEA AND STATE: Transpose across the diagonal, then
reverse each row. TRACE: [1,2;3,4] ->transpose[1,3;2,4] ->[3,1;4,2]. CORRECTNESS: The
composition maps old(row,column) to new(column,n-1-row). COST: O(n^2) time,O(1) auxiliary
space. PITFALL: Only swap the upper triangle during transpose, or each swap is undone.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& a) {
    std::size_t n = a.size();
    for (const auto& row : a) {
        assert(row.size() == n);
    }
    for (std::size_t r = 0; r < n; ++r) {
        for (std::size_t c = r + 1; c < n; ++c) {
            std::swap(a[r][c], a[c][r]);
        }
    }
    for (auto& row : a) {
        std::reverse(row.begin(), row.end());
    }
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};
    rotate(a);
    assert((a == std::vector<std::vector<int>>{{3, 1}, {4, 2}}));
    for (int i = 0; i < 3; ++i) {
        rotate(a);
    }
    assert((a == std::vector<std::vector<int>>{{1, 2}, {3, 4}}));
    std::vector<std::vector<int>> empty;
    rotate(empty);
    std::cout << "checks passed\n";
    return 0;
}
