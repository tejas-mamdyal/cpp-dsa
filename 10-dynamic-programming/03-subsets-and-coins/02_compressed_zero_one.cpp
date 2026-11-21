/*
 Single-use positive weights; capacity 0..1000; empty choice allowed. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[c] is best value after processed items; downward c means dp[c-weight]
still belongs to the earlier-item layer.

One item weight 2, value 3 at capacity 4 yields 3, not 6, because capacity 2 is
updated after capacity 4.

Descending writes cannot feed the current item into its own inclusion transition.

O(n*C) time, O(C) storage.

Ascending capacities turn this into an unbounded solver.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

long long knapsack(const std::vector<int>& w, const std::vector<int>& v, int capacity) {
    std::vector<long long> dp(static_cast<std::size_t>(capacity + 1), 0);
    for (std::size_t i = 0; i < w.size(); ++i) {
        assert(w[i] > 0);
        for (int c = capacity; c >= w[i]; --c) {
            dp[c] = std::max(dp[c], dp[c - w[i]] + v[i]);
        }
    }
    return dp[capacity];
}

int main() {
    assert(knapsack({2}, {3}, 4) == 3);
    assert(knapsack({10, 20, 30}, {60, 100, 120}, 50) == 220);
    std::cout << "checks passed\n";
    return 0;
}
