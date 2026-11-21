/*
 Rectangular grid<=30x 30;0 empty,1 fresh,2 rotten. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

Initial rotten cells share layer 0; fresh is decremented only when a fresh
cell first joins the frontier.

The standard 3x 3 fixture spreads through four layers; an isolated fresh cell
remains impossible.

Each layer contains exactly newly infected cells from the previous minute.

O(R*C) time/storage.

Empty cells block infection; not every grid cell is traversable.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <queue>
#include <cstddef>

std::optional<int> minutes(std::vector<std::vector<int>> a) {
    if (a.empty()) {
        return 0;
    }
    std::queue<std::pair<int, int>> q;
    int fresh = 0;
    for (int r = 0; r < static_cast<int>(a.size()); ++r) {
        for (int c = 0; c < static_cast<int>(a[0].size()); ++c) {
            if (a[r][c] == 2) {
                q.emplace(r, c);
            } else if (a[r][c] == 1) {
                ++fresh;
            }
        }
    }
    int time = 0;
    const int dr[4]{1, -1, 0, 0};
    const int dc[4]{0, 0, 1, -1};
    while (fresh > 0 && !q.empty()) {
        std::size_t size = q.size();
        for (std::size_t i = 0; i < size; ++i) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < static_cast<int>(a.size())
                    && nc < static_cast<int>(a[0].size()) && a[nr][nc] == 1) {
                    a[nr][nc] = 2;
                    --fresh;
                    q.emplace(nr, nc);
                }
            }
        }
        ++time;
    }
    if (fresh > 0) {
        return std::nullopt;
    }
    return time;
}

int main() {
    assert(minutes({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}) == 4);
    assert(!minutes({{2, 0, 1}}));
    assert(minutes({{0}}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
