/*
 From 0 to 8 rows/columns; updates use valid half-open rectangles and bounded signed
deltas.

IDEA AND STATE: Toggle each rectangle at four corners, then take a 2D prefix to reconstruct.

TRACE: 2x 2 adding 5 to[0,1)x[0,2) fills only the first row.

Adding5 across row0 uses corners+5,-5,-5,+5;the overlapping -2 update lowers column1 in both
rows.

The two prefix directions activate the interior and cancel beyond both end
boundaries.

O(R*C+q) time, O(R*C) storage.

Padding must accommodate row==R and column==C sentinels.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct RectangleAdd {
    int r0;
    int c0;
    int r1;
    int c1;
    int value;
};

std::vector<std::vector<long long>>
rectangleAdds(int rows, int columns, const std::vector<RectangleAdd>& updates) {
    std::vector<std::vector<long long>> d(
        static_cast<std::size_t>(rows + 1),
        std::vector<long long>(static_cast<std::size_t>(columns + 1), 0));
    for (const auto& u : updates) {
        assert(0 <= u.r0 && u.r0 <= u.r1 && u.r1 <= rows && 0 <= u.c0 && u.c0 <= u.c1
               && u.c1 <= columns);
        d[u.r0][u.c0] += u.value;
        d[u.r1][u.c0] -= u.value;
        d[u.r0][u.c1] -= u.value;
        d[u.r1][u.c1] += u.value;
    }
    std::vector<std::vector<long long>> out(
        static_cast<std::size_t>(rows), std::vector<long long>(static_cast<std::size_t>(columns)));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (r > 0) {
                d[r][c] += d[r - 1][c];
            }
            if (c > 0) {
                d[r][c] += d[r][c - 1];
            }
            if (r > 0 && c > 0) {
                d[r][c] -= d[r - 1][c - 1];
            }
            out[r][c] = d[r][c];
        }
    }
    return out;
}

int main() {
    assert((rectangleAdds(2, 2, {{0, 0, 1, 2, 5}, {0, 1, 2, 2, -2}})
            == std::vector<std::vector<long long>>{{5, 3}, {0, -2}}));
    assert(rectangleAdds(0, 0, {}).empty());
    std::cout << "checks passed\n";
    return 0;
}
