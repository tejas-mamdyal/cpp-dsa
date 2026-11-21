/*
 Rectangular 0/1 obstacle grid<=30x 30;1 blocked,0 open. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

dp[r][c] counts routes avoiding all blocked cells; blocked entries stay 0.

Center obstacle in 3x 3 leaves only the perimeter routes, so count 2.

The normal predecessor sum remains valid at open cells; blocked cells admit no
route.

O(R*C) time/storage.

A blocked origin must not be seeded with 1.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long paths(const std::vector<std::vector<int>>& blocked) {
    if (blocked.empty() || blocked[0].empty()) {
        return 0;
    }
    std::vector<std::vector<long long>> dp(blocked.size(),
                                           std::vector<long long>(blocked[0].size(), 0));
    for (std::size_t r = 0; r < blocked.size(); ++r) {
        for (std::size_t col = 0; col < blocked[0].size(); ++col) {
            if (blocked[r][col]) {
                continue;
            }
            if (r == 0 && col == 0) {
                dp[r][col] = 1;
            } else {
                if (r > 0) {
                    dp[r][col] += dp[r - 1][col];
                }
                if (col > 0) {
                    dp[r][col] += dp[r][col - 1];
                }
            }
        }
    }
    return dp.back().back();
}

int main() {
    assert(paths({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) == 2);
    assert(paths({{1}}) == 0);
    assert(paths({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
