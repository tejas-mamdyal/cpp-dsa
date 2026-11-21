/*
 Rectangular binary matrix at most 1000 rows/columns; empty area 0.

IDEA AND STATE: Increment heights on 1 and reset on 0; solve a histogram after each row.

TRACE: Two rows of three ones ->6.

The first all-one row gives heights1,1,1 and area3;the next gives2,2,2 and area6.

Every all-one rectangle ends on some row, and its height is bounded by that row
histogram.

O(R*C) time, O(C) space.

A zero resets the column instead of preserving old height.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long histogram(const std::vector<int>& h) {
    std::vector<int> stack;
    long long best = 0;
    int n = static_cast<int>(h.size());
    for (int i = 0; i <= n; ++i) {
        int height = i == n ? 0 : h[i];
        while (!stack.empty() && h[stack.back()] >= height) {
            int top = stack.back();
            stack.pop_back();
            int left = stack.empty() ? -1 : stack.back();
            best = std::max(best, 1LL * h[top] * (i - left - 1));
        }
        if (i < n) {
            stack.push_back(i);
        }
    }
    return best;
}

long long binaryRectangle(const std::vector<std::vector<int>>& a) {
    if (a.empty()) {
        return 0;
    }
    std::vector<int> h(a[0].size(), 0);
    long long best = 0;
    for (const auto& row : a) {
        assert(row.size() == h.size());
        for (std::size_t c = 0; c < h.size(); ++c) {
            assert(row[c] == 0 || row[c] == 1);
            h[c] = row[c] == 0 ? 0 : h[c] + 1;
        }
        best = std::max(best, histogram(h));
    }
    return best;
}

int main() {
    assert(binaryRectangle({{1, 1, 1}, {1, 1, 1}}) == 6);
    assert(binaryRectangle({{1, 0, 1}, {1, 1, 1}}) == 3);
    assert(binaryRectangle({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
