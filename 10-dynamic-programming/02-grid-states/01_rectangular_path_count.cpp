/*
 Rows and columns 0..30; counts fit long long for these dimensions. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[r][c] counts down/right routes from 0,0 to r, c; only origin starts
with 1.

A 2x 3 grid table is 1,1,1 then 1,2,3.

Every nonorigin route enters uniquely from above or left; the cases are disjoint.

O(R*C) time/storage.

Zero dimensions have no destination, not one empty route.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long paths(int rows, int cols) {
    assert(rows >= 0 && rows <= 30 && cols >= 0 && cols <= 30);
    if (rows == 0 || cols == 0) {
        return 0;
    }
    std::vector<std::vector<long long>> dp(
        static_cast<std::size_t>(rows), std::vector<long long>(static_cast<std::size_t>(cols), 0));
    dp[0][0] = 1;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (r > 0) {
                dp[r][c] += dp[r - 1][c];
            }
            if (c > 0) {
                dp[r][c] += dp[r][c - 1];
            }
        }
    }
    return dp.back().back();
}

int main() {
    assert(paths(3, 4) == 10);
    assert(paths(1, 1) == 1);
    assert(paths(0, 3) == 0);
    std::cout << "checks passed\n";
    return 0;
}
