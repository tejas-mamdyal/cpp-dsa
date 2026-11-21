/*
 Nonnegative prices; after selling, one full day forbids buying. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

hold means a share is held, sold means sold today, rest means no share and
no sale today. Only rest can buy tomorrow.

Buy 1, sell 2, cooldown at 3, buy 0, sell 2 gives 3 total.

The separate sold state prevents a sale balance from immediately funding a
next-day purchase.

O(n) time, O(1) auxiliary.

Merging sold with rest too early removes the cooldown rule.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

long long profit(const std::vector<int>& prices) {
    const long long neg = std::numeric_limits<long long>::lowest() / 4;
    long long hold = neg;
    long long sold = neg;
    long long rest = 0;
    for (int p : prices) {
        long long nextHold = std::max(hold, rest - p);
        long long nextSold = hold == neg ? neg : hold + p;
        long long nextRest = std::max(rest, sold);
        hold = nextHold;
        sold = nextSold;
        rest = nextRest;
    }
    return std::max(rest, sold);
}

int main() {
    assert(profit({1, 2, 3, 0, 2}) == 3);
    assert(profit({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
