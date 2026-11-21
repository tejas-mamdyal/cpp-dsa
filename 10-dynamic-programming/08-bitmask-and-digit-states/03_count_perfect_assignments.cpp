/*
 Square 0/1 permission matrix, n 0..12.

dp[mask] counts ways to assign the first set-bit-count workers to exactly
the used jobs, using only permitted cells.

Two workers with all jobs allowed have two permutations; both restricted to job 0
have none.

Each next-worker assignment is a disjoint extension of a smaller partial
bijection.

O(n*2^n) time, O(2^n) table; n! fits n<=12.

This counts perfect assignments, not arbitrary matchings with unassigned workers.
*/
#include <iostream>
#include <cassert>
#include <vector>

int bits(unsigned int mask) {
    int count = 0;
    while (mask) {
        mask &= mask - 1U;
        ++count;
    }
    return count;
}

long long assignments(const std::vector<std::vector<int>>& allowed) {
    int n = static_cast<int>(allowed.size());
    assert(n <= 12);
    std::vector<long long> dp(1U << n, 0);
    dp[0] = 1;
    for (unsigned int mask = 0; mask < dp.size(); ++mask) {
        int worker = bits(mask);
        if (worker == n) {
            continue;
        }
        for (int job = 0; job < n; ++job) {
            if (allowed[worker][job] && (mask & (1U << job)) == 0U) {
                dp[mask | (1U << job)] += dp[mask];
            }
        }
    }
    return dp.back();
}

int main() {
    assert(assignments({{1, 1}, {1, 1}}) == 2);
    assert(assignments({{1, 0}, {1, 0}}) == 0);
    assert(assignments({}) == 1);
    std::cout << "checks passed\n";
    return 0;
}
