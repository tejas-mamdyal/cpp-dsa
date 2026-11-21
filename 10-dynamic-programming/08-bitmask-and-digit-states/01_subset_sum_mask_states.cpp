/*
 At most 16 signed values; unsigned masks fit the stated shift width. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[mask] is the sum of values at set-bit positions; remove one chosen bit
and add its value to a previously computed subset.

Mask 11 for 3,-1 uses dp 10=-1 plus first value 3 to get 2.

Removing one set position partitions the subset into its remaining positions and
that one value exactly.

O(n*2^n) time with a portable bit-index scan, O(2^n) table.

Bit positions describe input indices, not distinct numeric values.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

std::vector<long long> sums(const std::vector<int>& a) {
    assert(a.size() <= 16);
    std::size_t size = 1U << a.size();
    std::vector<long long> dp(size, 0);
    for (unsigned int mask = 1; mask < size; ++mask) {
        int bit = 0;
        while ((mask & (1U << bit)) == 0U) {
            ++bit;
        }
        dp[mask] = dp[mask ^ (1U << bit)] + a[bit];
    }
    return dp;
}

int main() {
    assert((sums({3, -1}) == std::vector<long long>{0, 3, -1, 2}));
    assert(sums({}) == std::vector<long long>{0});
    std::cout << "checks passed\n";
    return 0;
}
