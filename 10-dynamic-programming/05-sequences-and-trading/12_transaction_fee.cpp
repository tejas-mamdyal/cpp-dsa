/*
 Nonnegative prices and fee; unlimited transactions, one held share maximum. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

The unlimited cash/hold states remain sufficient; the sale transition
subtracts the fixed fee once.

Buy 1, sell 8 fee 2 gives 5; buy 4, sell 9 fee 2 gives 3, total 8.

Each completed transaction has exactly one sale, so charging there counts the fee
exactly once.

O(n) time, O(1) storage.

Charging on both buy and sale doubles the specified fee.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

long long profit(const std::vector<int>& prices, int fee) {
    assert(fee >= 0);
    long long hold = std::numeric_limits<long long>::lowest() / 4;
    long long cash = 0;
    for (int p : prices) {
        long long nextCash = std::max(cash, hold + p - fee);
        long long nextHold = std::max(hold, cash - p);
        cash = nextCash;
        hold = nextHold;
    }
    return cash;
}

int main() {
    assert(profit({1, 3, 2, 8, 4, 9}, 2) == 8);
    assert(profit({1, 2}, 5) == 0);
    std::cout << "checks passed\n";
    return 0;
}
