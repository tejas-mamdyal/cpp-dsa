/*
 Nonempty rectangular signed grid<=30x 30; start anywhere in top row, end anywhere in
bottom row.

previous[c] is the best path ending at column c of the preceding row; new
rows allow down-left, down, down-right.

First row 2,1,3 becomes 7,6,5, then 13,13,14; minimum 13.

Every allowed falling path reaches its last cell from one of those three
predecessor columns.

O(R*C) time, O(C) auxiliary.

Updating the same row left-to-right would accidentally use current-row values.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>
#include <cstddef>

std::optional<long long> falling(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        return std::nullopt;
    }
    std::vector<long long> previous(a[0].begin(), a[0].end());
    for (std::size_t r = 1; r < a.size(); ++r) {
        std::vector<long long> next(previous.size());
        for (std::size_t c = 0; c < previous.size(); ++c) {
            long long best = previous[c];
            if (c > 0) {
                best = std::min(best, previous[c - 1]);
            }
            if (c + 1 < previous.size()) {
                best = std::min(best, previous[c + 1]);
            }
            next[c] = best + a[r][c];
        }
        previous = std::move(next);
    }
    return *std::min_element(previous.begin(), previous.end());
}

int main() {
    assert(falling({{2, 1, 3}, {6, 5, 4}, {7, 8, 9}}) == 13);
    assert(!falling({}));
    std::cout << "checks passed\n";
    return 0;
}
