/*
 Rectangular binary-character matrix<=5x 5.

heights[col] counts consecutive 1 cells ending at the current row.

At the third row, a width 3, height 2 rectangle has area 6.

Every all-one rectangle has a bottom row and corresponds to a histogram rectangle
there.

O(rows*cols) time, O(cols) work.

Reset heights to 0 at a zero cell instead of carrying the previous run.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>

int histogram(const std::vector<int>& heights) {
    std::vector<int> stack;
    int best = 0;
    for (int i = 0; i <= static_cast<int>(heights.size()); ++i) {
        int current = i == static_cast<int>(heights.size()) ? 0 : heights[i];
        while (!stack.empty() && heights[stack.back()] > current) {
            int h = heights[stack.back()];
            stack.pop_back();
            int left = stack.empty() ? -1 : stack.back();
            best = std::max(best, h * (i - left - 1));
        }
        stack.push_back(i);
    }
    return best;
}

int rectangle(const std::vector<std::string>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    std::vector<int> heights(matrix[0].size());
    int best = 0;
    for (auto& row : matrix) {
        for (std::size_t col = 0; col < row.size(); ++col) {
            heights[col] = row[col] == '1' ? heights[col] + 1 : 0;
        }
        best = std::max(best, histogram(heights));
    }
    return best;
}

int main() {
    assert(rectangle({"10100", "10111", "11111", "10010"}) == 6);
    assert(rectangle({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
