/*
 nodes 0..15, height 0..15 measured in nodes; ordered unlabeled shapes. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[h][n] counts ordered binary shapes with n nodes and height in nodes at
most h; empty fits any h.

Three nodes fit height 2 only as a root with two leaves; height 3 admits all five
shapes.

Both child heights must be at most h-1; sum products over every left/right
node-size split.

O(H*n^2) time, O(H*n) table.

At-most height and exactly height are different counts; exactly H subtracts the
at-most H-1 count.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long boundedTrees(int nodes, int height) {
    assert(nodes >= 0 && nodes <= 15 && height >= 0 && height <= 15);
    std::vector<std::vector<long long>> dp(
        static_cast<std::size_t>(height + 1),
        std::vector<long long>(static_cast<std::size_t>(nodes + 1), 0));
    for (int h = 0; h <= height; ++h) {
        dp[h][0] = 1;
    }
    for (int h = 1; h <= height; ++h) {
        for (int n = 1; n <= nodes; ++n) {
            for (int left = 0; left < n; ++left) {
                dp[h][n] += dp[h - 1][left] * dp[h - 1][n - 1 - left];
            }
        }
    }
    return dp[height][nodes];
}

int main() {
    assert(boundedTrees(3, 2) == 1);
    assert(boundedTrees(3, 3) == 5);
    assert(boundedTrees(0, 0) == 1);
    assert(boundedTrees(1, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
