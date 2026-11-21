/*
 Nonempty rectangular integer height grid<=30x 30; four-neighbor moves. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

Distance is the smallest achievable maximum adjacent height difference
along a route.

The 3x 3 fixture can follow 1,3,5,3,5 with maximum jump 2.

Extending a route cannot decrease its maximum edge effort, so the
minimum-frontier finalization argument remains valid.

O(R*C log(R*C+1)) time, O(R*C) states/heap.

Summing differences solves a different objective.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <tuple>
#include <cstdlib>
#include <functional>

long long effort(const std::vector<std::vector<int>>& a) {
    assert(!a.empty() && !a[0].empty());
    int rows = static_cast<int>(a.size());
    int cols = static_cast<int>(a[0].size());
    const long long inf = std::numeric_limits<long long>::max() / 4;
    std::vector<std::vector<long long>> d(a.size(), std::vector<long long>(a[0].size(), inf));
    using Item = std::tuple<long long, int, int>;
    std::priority_queue<Item, std::vector<Item>, std::greater<Item>> q;
    d[0][0] = 0;
    q.emplace(0, 0, 0);
    const int dr[4]{1, -1, 0, 0};
    const int dc[4]{0, 0, 1, -1};
    while (!q.empty()) {
        auto [cost, r, c] = q.top();
        q.pop();
        if (cost != d[r][c]) {
            continue;
        }
        if (r == rows - 1 && c == cols - 1) {
            return cost;
        }
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                continue;
            }
            long long candidate = std::max(cost, std::abs(1LL * a[r][c] - a[nr][nc]));
            if (candidate < d[nr][nc]) {
                d[nr][nc] = candidate;
                q.emplace(candidate, nr, nc);
            }
        }
    }
    return 0;
}

int main() {
    assert(effort({{1, 2, 2}, {3, 8, 2}, {5, 3, 5}}) == 2);
    assert(effort({{7}}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
