/*
 Nonnegative daily prices, length<=30; at most one held share; may choose no trade.

hold is best value after one purchase and before any sale; cash is best
completed at-most-one-sale profit.

Buy at 1 creates hold-1; sell at 6 creates cash 5.

The best single purchase is the minimum prior price; each possible sale combines
with that state.

O(n) time, O(1) auxiliary.

Buying from previous cash would permit additional transactions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

long long profit(const std::vector<int>& prices) {
    long long hold = std::numeric_limits<long long>::lowest() / 4;
    long long cash = 0;
    for (int p : prices) {
        long long nextCash = std::max(cash, hold + p);
        hold = std::max(hold, -1LL * p);
        cash = nextCash;
    }
    return cash;
}

int main() {
    assert(profit({7, 1, 5, 3, 6, 4}) == 5);
    assert(profit({7, 6, 4}) == 0);
    assert(profit({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
