/*
 Rectangular 0/1 obstacle grid<=30x 30;1 blocked.

Before updating c, dp[c] is the previous row above count; dp[c-1] is
already the current row left count.

A blocked middle slot resets its old above count to 0 before later columns
continue.

Left-to-right overwrite retains exactly the two predecessor values needed by the
full table.

O(R*C) time, O(C) storage.

Leaving a blocked slot unchanged leaks routes through an obstacle.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long paths(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        return 0;
    }
    std::vector<long long> dp(a[0].size(), 0);
    dp[0] = 1;
    for (const auto& row : a) {
        for (std::size_t c = 0; c < row.size(); ++c) {
            if (row[c]) {
                dp[c] = 0;
            } else if (c > 0) {
                dp[c] += dp[c - 1];
            }
        }
    }
    return dp.back();
}

int main() {
    assert(paths({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) == 2);
    assert(paths({{0, 1}, {0, 0}}) == 1);
    assert(paths({{1}}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
