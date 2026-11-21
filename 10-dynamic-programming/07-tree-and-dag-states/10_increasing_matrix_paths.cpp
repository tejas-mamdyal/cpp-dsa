/*
 Rectangular signed grid<=30x 30; strictly increasing four-neighbor paths. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

memo[r][c] is maximum increasing path length starting at that cell,
including it;0 means unknown.

The fixture admits 1,2,6,9 of length 4; equal neighboring 9 values cannot extend.

Every allowed edge strictly increases value, so no cycle is possible; maximize 1
plus all legal child suffixes.

O(R*C) time/storage plus worst-case O(R*C) recursion.

Nondecreasing moves can cycle among equal cells and require a different model.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int solve(const std::vector<std::vector<int>>& a,
          int r,
          int c,
          std::vector<std::vector<int>>& memo) {
    if (memo[r][c] != 0) {
        return memo[r][c];
    }
    int best = 1;
    const int dr[4]{1, -1, 0, 0};
    const int dc[4]{0, 0, 1, -1};
    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr >= 0 && nc >= 0 && nr < static_cast<int>(a.size())
            && nc < static_cast<int>(a[0].size()) && a[nr][nc] > a[r][c]) {
            best = std::max(best, 1 + solve(a, nr, nc, memo));
        }
    }
    memo[r][c] = best;
    return best;
}

int longest(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        return 0;
    }
    std::vector<std::vector<int>> memo(a.size(), std::vector<int>(a[0].size(), 0));
    int best = 0;
    for (int r = 0; r < static_cast<int>(a.size()); ++r) {
        for (int c = 0; c < static_cast<int>(a[0].size()); ++c) {
            best = std::max(best, solve(a, r, c, memo));
        }
    }
    return best;
}

int main() {
    assert(longest({{9, 9, 4}, {6, 6, 8}, {2, 1, 1}}) == 4);
    assert(longest({{2, 2}}) == 1);
    assert(longest({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
