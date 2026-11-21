/*
 Rectangular matrix at most 8 by 8; nonempty rectangle; empty absent.

IDEA AND STATE: For each top and bottom row, add column totals and run Kadane.

TRACE: [[1,-2],[3,4]] has optimum 7 from the bottom row. The whole matrix sums to 6.

Top row alone yields1;both rows compress to4,2 and yield6;bottom row alone yields7,which wins.

Every rectangle has a unique top/bottom pair; Kadane chooses its best contiguous
columns.

O(R*R*C) time, O(C) auxiliary space.

Rows must have equal lengths; initialize from actual values for negative matrices.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<long long> maximum(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    long long ending = a[0];
    long long best = ending;
    for (std::size_t i = 1; i < a.size(); ++i) {
        ending = std::max(1LL * a[i], ending + a[i]);
        best = std::max(best, ending);
    }
    return best;
}

std::optional<long long> rectangle(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        return std::nullopt;
    }
    std::optional<long long> best;
    for (std::size_t top = 0; top < a.size(); ++top) {
        std::vector<int> sums(a[0].size(), 0);
        for (std::size_t bottom = top; bottom < a.size(); ++bottom) {
            assert(a[bottom].size() == a[0].size());
            for (std::size_t c = 0; c < sums.size(); ++c) {
                sums[c] += a[bottom][c];
            }
            long long value = *maximum(sums);
            if (!best || value > *best) {
                best = value;
            }
        }
    }
    return best;
}

int main() {
    assert(rectangle({{1, -2}, {3, 4}}) == 7);
    assert(rectangle({{-8, -3}, {-4, -9}}) == -3);
    assert(!rectangle({}));
    std::cout << "checks passed\n";
    return 0;
}
