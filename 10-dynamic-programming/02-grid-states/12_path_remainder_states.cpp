/*
 Rectangular signed grid<=30x 30; k 1..10; counts fit the stated grid bounds. Unless
a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[r][c][rem] counts routes ending at r, c with path sum remainder rem
modulo k; normalize negative input remainders.

2x 2 routes sum 1+2+4=7 and 1+3+4=8; only the latter is divisible by 2.

Appending a cell updates only the sum remainder, which is sufficient for all
future remainder tests.

O(R*C*k) time/storage.

The original sum can be negative; raw C++ negative remainders are not valid vector
indices.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long divisiblePaths(const std::vector<std::vector<int>>& a, int k) {
    assert(k >= 1 && k <= 10);
    if (a.empty() || a[0].empty()) {
        return 0;
    }
    std::vector<std::vector<std::vector<long long>>> dp(
        a.size(),
        std::vector<std::vector<long long>>(
            a[0].size(), std::vector<long long>(static_cast<std::size_t>(k), 0)));
    int start = (a[0][0] % k + k) % k;
    dp[0][0][start] = 1;
    for (std::size_t r = 0; r < a.size(); ++r) {
        for (std::size_t c = 0; c < a[0].size(); ++c) {
            if (r == 0 && c == 0) {
                continue;
            }
            for (int rem = 0; rem < k; ++rem) {
                int next = (rem + a[r][c] % k + k) % k;
                if (r > 0) {
                    dp[r][c][next] += dp[r - 1][c][rem];
                }
                if (c > 0) {
                    dp[r][c][next] += dp[r][c - 1][rem];
                }
            }
        }
    }
    return dp.back().back()[0];
}

int main() {
    assert(divisiblePaths({{1, 2}, {3, 4}}, 2) == 1);
    assert(divisiblePaths({{-1, 1}}, 2) == 1);
    assert(divisiblePaths({}, 3) == 0);
    std::cout << "checks passed\n";
    return 0;
}
