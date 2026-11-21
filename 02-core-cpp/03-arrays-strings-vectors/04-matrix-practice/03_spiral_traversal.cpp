/*
SPIRAL TRAVERSAL OF A RECTANGULAR MATRIX
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Track inclusive top,bottom,left,right boundaries; guard the final bottom and left passes. Matrix rows have equal size.
Trace: [1,2,3;4,5,6] emits1,2,3,6,5,4.
Why it works: Each pass consumes one remaining boundary, so no cell is visited twice.
Cost: O(rows*columns) time and O(rows*columns) output storage.
Common mistake: Without guards a one-row or one-column remainder is emitted twice.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> spiral(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return {};
    }
    int top = 0;
    int bottom = static_cast<int>(matrix.size()) - 1;
    int left = 0;
    int right = static_cast<int>(matrix[0].size()) - 1;
    std::vector<int> result;
    while (top <= bottom && left <= right) {
        for (int column = left; column <= right; ++column) {
            result.push_back(matrix[top][column]);
        }
        ++top;
        for (int row = top; row <= bottom; ++row) {
            result.push_back(matrix[row][right]);
        }
        --right;
        if (top <= bottom) {
            for (int column = right; column >= left; --column) {
                result.push_back(matrix[bottom][column]);
            }
            --bottom;
        }
        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                result.push_back(matrix[row][left]);
            }
            ++left;
        }
    }
    return result;
}

int main() {
    assert((spiral({{1, 2, 3}, {4, 5, 6}}) == std::vector<int>{1, 2, 3, 6, 5, 4}));
    assert((spiral({{1}, {2}, {3}}) == std::vector<int>{1, 2, 3}));
    assert(spiral({}).empty());
    std::cout << "checks passed\n";
}
