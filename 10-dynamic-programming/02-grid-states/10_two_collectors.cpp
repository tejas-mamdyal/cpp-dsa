/*
 Nonempty nonnegative grid<=30x 30; two agents move one row down each step. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[x][y] is maximum collected total with two agents at columns x, y in the
current row; they start at the two top corners.

The standard four-row fixture achieves 24; one-column input counts each shared
cell only once.

Both next columns move by-1,0,1; trying all nine legal pairs covers every joint
route and counts shared rewards once.

O(R*C^2*9) time, O(C^2) auxiliary.

Solving each agent independently can double-count cells or miss interacting route
choices.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cstddef>

long long collect(const std::vector<std::vector<int>>& a) {
    assert(!a.empty() && !a[0].empty());
    int cols = static_cast<int>(a[0].size());
    const long long neg = std::numeric_limits<long long>::lowest() / 4;
    std::vector<std::vector<long long>> dp(
        static_cast<std::size_t>(cols),
        std::vector<long long>(static_cast<std::size_t>(cols), neg));
    dp[0][cols - 1] = a[0][0] + (cols == 1 ? 0 : a[0][cols - 1]);
    for (std::size_t r = 1; r < a.size(); ++r) {
        auto next = std::vector<std::vector<long long>>(
            static_cast<std::size_t>(cols),
            std::vector<long long>(static_cast<std::size_t>(cols), neg));
        for (int x = 0; x < cols; ++x) {
            for (int y = 0; y < cols; ++y) {
                if (dp[x][y] == neg) {
                    continue;
                }
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx < 0 || ny < 0 || nx >= cols || ny >= cols) {
                            continue;
                        }
                        long long value = a[r][nx] + (nx == ny ? 0 : a[r][ny]);
                        next[nx][ny] = std::max(next[nx][ny], dp[x][y] + value);
                    }
                }
            }
        }
        dp = std::move(next);
    }
    long long best = neg;
    for (const auto& row : dp) {
        best = std::max(best, *std::max_element(row.begin(), row.end()));
    }
    return best;
}

int main() {
    assert(collect({{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}}) == 24);
    assert(collect({{2}, {3}}) == 5);
    std::cout << "checks passed\n";
    return 0;
}
