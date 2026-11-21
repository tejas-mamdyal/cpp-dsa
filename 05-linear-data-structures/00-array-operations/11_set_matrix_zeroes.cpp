/*
ZERO MARKED ROWS AND COLUMNS WITH EXPLICIT MARKER STORAGE PREREQUISITES: Phases1/2 C++ and

unit README order, not old filenames.

 Rectangular matrix; original zeros determine affected rows/columns. IDEA AND STATE:
First record zero locations, then rewrite in a separate pass. TRACE: [1,0;3,4] ->[0,0;3,0].
CORRECTNESS: Markers depend only on original data, so newly written zeros do not cascade.
COST: O(rows*columns) time,O(rows+columns) auxiliary space. PITFALL: Mutating while
discovering zeros incorrectly propagates new marks. PRACTICE: Change the example, predict each
state update and add an empty/boundary case. No input unless explicitly stated. Assertions are
the teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void zeroes(std::vector<std::vector<int>>& a) {
    if (a.empty()) {
        return;
    }
    std::size_t rows = a.size();
    std::size_t columns = a[0].size();
    std::vector<bool> rowZero(rows, false);
    std::vector<bool> colZero(columns, false);
    for (std::size_t r = 0; r < rows; ++r) {
        assert(a[r].size() == columns);
        for (std::size_t c = 0; c < columns; ++c) {
            if (a[r][c] == 0) {
                rowZero[r] = true;
                colZero[c] = true;
            }
        }
    }
    for (std::size_t r = 0; r < rows; ++r) {
        for (std::size_t c = 0; c < columns; ++c) {
            if (rowZero[r] || colZero[c]) {
                a[r][c] = 0;
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> a = {{1, 0}, {3, 4}};
    zeroes(a);
    assert((a == std::vector<std::vector<int>>{{0, 0}, {3, 0}}));
    std::vector<std::vector<int>> empty;
    zeroes(empty);
    std::vector<std::vector<int>> b = {{5}};
    zeroes(b);
    assert(b[0][0] == 5);
    std::cout << "checks passed\n";
    return 0;
}
