/*
 Nonnegative prices, n<=30, k 0..10; at most k completed transactions. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

cash[t] is best balance with exactly t completed sales and no share;
hold[t] has t sales and one share. Unknown histories are neg.

With budget 2, buy 2, sell 6 then buy 0, sell 3 gives 7; budget 0 permits only
resting.

Buying preserves completed-sale count; selling increments it once. Previous-day
snapshots cover all legal action histories.

O(n*k) time, O(k) storage.

Do not return an infeasible exact-k value when the contract permits at most k;
maximize all final cash budgets.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cstddef>

long long profit(const std::vector<int>& prices, int k) {
    assert(k >= 0 && k <= 10);
    const long long neg = std::numeric_limits<long long>::lowest() / 4;
    std::vector<long long> cash(static_cast<std::size_t>(k + 1), neg);
    std::vector<long long> hold(static_cast<std::size_t>(k + 1), neg);
    cash[0] = 0;
    for (int p : prices) {
        auto nextCash = cash;
        auto nextHold = hold;
        for (int sold = 0; sold < k; ++sold) {
            if (cash[sold] != neg) {
                nextHold[sold] = std::max(nextHold[sold], cash[sold] - p);
            }
            if (hold[sold] != neg) {
                nextCash[sold + 1] = std::max(nextCash[sold + 1], hold[sold] + p);
            }
        }
        cash = std::move(nextCash);
        hold = std::move(nextHold);
    }
    return *std::max_element(cash.begin(), cash.end());
}

int main() {
    assert(profit({3, 2, 6, 5, 0, 3}, 2) == 7);
    assert(profit({1, 3}, 0) == 0);
    assert(profit({}, 3) == 0);
    std::cout << "checks passed\n";
    return 0;
}
