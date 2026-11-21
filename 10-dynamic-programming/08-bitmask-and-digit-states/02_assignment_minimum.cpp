/*
 Square signed cost matrix, n 0..12; every worker/job used exactly once. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[mask] is minimum cost assigning the first popcount(mask) workers to
exactly those jobs; next worker is not a separate state.

Assignments worker 0->job 1 cost 2, worker 1->job 0 cost 6, worker 2->job 2 cost
1, total 9.

Every complete bijection assigns one unused job to the next worker; all smaller
masks are processed first.

O(n*2^n) time, O(2^n) states.

A missing job-permission constraint requires skipping forbidden transitions rather
than assigning them a free 0 cost.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

int bits(unsigned int mask) {
    int count = 0;
    while (mask) {
        mask &= mask - 1U;
        ++count;
    }
    return count;
}

long long assignment(const std::vector<std::vector<int>>& cost) {
    int n = static_cast<int>(cost.size());
    assert(n <= 12);
    long long inf = std::numeric_limits<long long>::max() / 4;
    std::vector<long long> dp(1U << n, inf);
    dp[0] = 0;
    for (unsigned int mask = 0; mask < dp.size(); ++mask) {
        int worker = bits(mask);
        if (worker == n) {
            continue;
        }
        for (int job = 0; job < n; ++job) {
            if ((mask & (1U << job)) == 0U) {
                unsigned int next = mask | (1U << job);
                dp[next] = std::min(dp[next], dp[mask] + cost[worker][job]);
            }
        }
    }
    return dp.back();
}

int main() {
    assert(assignment({{9, 2, 7}, {6, 4, 3}, {5, 8, 1}}) == 9);
    assert(assignment({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
