/*
 Rectangular input; queries use valid half-open row/column bounds.

IDEA AND STATE: Build one extra zero row/column; subtract above and left, add their shared
corner back.

TRACE: [1,2,3;4,5,6], rows 0..2, columns 1..3 ->16.

Padded prefix at row2,column3 is21;subtract the first-column sum5 to get16.

Inclusion-exclusion retains exactly the queried rectangle once.

O(R*C) build/storage, O(1) query.

Using an inclusive bottom/right in this formula is an off-by-one error.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using Matrix = std::vector<std::vector<long long>>;

Matrix prefix2D(const std::vector<std::vector<int>>& a) {
    std::size_t rows = a.size();
    std::size_t columns = 0;
    if (rows > 0) {
        columns = a[0].size();
    }
    Matrix p(rows + 1, std::vector<long long>(columns + 1, 0));
    for (std::size_t r = 0; r < rows; ++r) {
        assert(a[r].size() == columns);
        for (std::size_t c = 0; c < columns; ++c) {
            p[r + 1][c + 1] = a[r][c] + p[r][c + 1] + p[r + 1][c] - p[r][c];
        }
    }
    return p;
}

long long
rectangle(const Matrix& p, std::size_t r0, std::size_t c0, std::size_t r1, std::size_t c1) {
    return p[r1][c1] - p[r0][c1] - p[r1][c0] + p[r0][c0];
}

int main() {
    auto p = prefix2D({{1, 2, 3}, {4, 5, 6}});
    assert(rectangle(p, 0, 1, 2, 3) == 16);
    assert(rectangle(p, 1, 1, 2, 2) == 5);
    assert(rectangle(p, 0, 0, 0, 3) == 0);
    assert(rectangle(prefix2D({}), 0, 0, 0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
