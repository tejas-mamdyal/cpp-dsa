/*
 Positive weights, nonnegative values; unlimited copies; capacity 0..1000. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[c] is best at-most-capacity value using processed reusable item types;
smaller capacities may already include this type.

Weight 2, value 3 updates capacities 2 to 3 and 4 to 6 using two copies.

Every included final copy leaves a smaller capacity whose best solution may use
the same type.

O(n*C) time, O(C) storage.

Zero weight with positive value makes this optimum unbounded and violates the
contract.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

long long unbounded(const std::vector<int>& w, const std::vector<int>& v, int capacity) {
    std::vector<long long> dp(static_cast<std::size_t>(capacity + 1), 0);
    for (std::size_t i = 0; i < w.size(); ++i) {
        assert(w[i] > 0);
        for (int c = w[i]; c <= capacity; ++c) {
            dp[c] = std::max(dp[c], dp[c - w[i]] + v[i]);
        }
    }
    return dp[capacity];
}

int main() {
    assert(unbounded({2}, {3}, 4) == 6);
    assert(unbounded({3, 4}, {4, 5}, 6) == 8);
    std::cout << "checks passed\n";
    return 0;
}
