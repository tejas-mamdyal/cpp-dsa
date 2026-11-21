/*
 Signed rectangular grid<=30x 30; return any optimum under left-on-tie policy. Unless
a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp stores optimum costs; parent records L or U, choosing left on equal
costs for deterministic local ties.

2x 2 values 1,2/3,4 choose path(0,0),(0,1),(1,1), sum 7.

Each recorded parent attains the stored optimum; following parents reduces
row+column until origin.

O(R*C) time/storage plus O(R+C) witness.

A compressed cost row alone cannot recover overwritten parent decisions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>

std::optional<std::pair<long long, std::vector<std::pair<int, int>>>>
route(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        return std::nullopt;
    }
    int rows = static_cast<int>(a.size());
    int cols = static_cast<int>(a[0].size());
    std::vector<std::vector<long long>> dp(a.size(), std::vector<long long>(a[0].size()));
    std::vector<std::vector<char>> parent(a.size(), std::vector<char>(a[0].size()));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (r == 0 && c == 0) {
                dp[r][c] = a[r][c];
            } else if (r == 0 || (c > 0 && dp[r][c - 1] <= dp[r - 1][c])) {
                dp[r][c] = dp[r][c - 1] + a[r][c];
                parent[r][c] = 'L';
            } else {
                dp[r][c] = dp[r - 1][c] + a[r][c];
                parent[r][c] = 'U';
            }
        }
    }
    std::vector<std::pair<int, int>> path;
    int r = rows - 1;
    int col = cols - 1;
    while (true) {
        path.emplace_back(r, col);
        if (r == 0 && col == 0) {
            break;
        }
        if (parent[r][col] == 'L') {
            --col;
        } else {
            --r;
        }
    }
    std::reverse(path.begin(), path.end());
    return std::pair<long long, std::vector<std::pair<int, int>>>{dp.back().back(), path};
}

int main() {
    auto answer = route({{1, 2}, {3, 4}});
    assert(answer && answer->first == 7
           && (answer->second == std::vector<std::pair<int, int>>{{0, 0}, {0, 1}, {1, 1}}));
    assert(!route({}));
    std::cout << "checks passed\n";
    return 0;
}
