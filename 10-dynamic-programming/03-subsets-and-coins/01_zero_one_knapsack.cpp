/*
 At most 30 items, positive weights, signed values; capacity 0..1000. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[i][c] is maximum value from first i items using total weight at most c;
empty selection is legal.

Capacity 50 chooses weights 20+30, value 220; fractional 240 is not an admissible
item subset.

An optimum excludes item i or includes it once and uses only earlier items in the
remaining capacity.

O(n*C) time/storage.

Reading the same item row for inclusion would permit reuse.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

long long knapsack(const std::vector<int>& weight, const std::vector<int>& value, int capacity) {
    assert(weight.size() == value.size() && capacity >= 0 && capacity <= 1000);
    std::vector<std::vector<long long>> dp(
        weight.size() + 1, std::vector<long long>(static_cast<std::size_t>(capacity + 1), 0));
    for (std::size_t i = 1; i <= weight.size(); ++i) {
        assert(weight[i - 1] > 0);
        for (int c = 0; c <= capacity; ++c) {
            dp[i][c] = dp[i - 1][c];
            if (weight[i - 1] <= c) {
                dp[i][c] = std::max(dp[i][c], value[i - 1] + dp[i - 1][c - weight[i - 1]]);
            }
        }
    }
    return dp.back()[capacity];
}

int main() {
    assert(knapsack({10, 20, 30}, {60, 100, 120}, 50) == 220);
    assert(knapsack({1}, {-5}, 1) == 0);
    assert(knapsack({}, {}, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
