/*
 Nonnegative prices; at most two transactions, one share maximum. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

buy 1/sell 1 are holding/cash balances with at most one trade; buy 2/sell
2 extend that budget to two. Cash bases 0 allow fewer trades.

Buy 0, sell 3 then buy 1, sell 4 yields 6 in the standard fixture.

Each state rests or performs the next allowed buy/sale from the previous budget
stage.

O(n) time, O(1) auxiliary.

Two transactions mean two completed sales, not two arbitrary buy/sell actions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

long long profit(const std::vector<int>& prices) {
    long long buy1 = std::numeric_limits<long long>::lowest() / 4;
    long long buy2 = buy1;
    long long sell1 = 0;
    long long sell2 = 0;
    for (int p : prices) {
        long long nextBuy1 = std::max(buy1, -1LL * p);
        long long nextSell1 = std::max(sell1, buy1 + p);
        long long nextBuy2 = std::max(buy2, sell1 - p);
        long long nextSell2 = std::max(sell2, buy2 + p);
        buy1 = nextBuy1;
        sell1 = nextSell1;
        buy2 = nextBuy2;
        sell2 = nextSell2;
    }
    return sell2;
}

int main() {
    assert(profit({3, 3, 5, 0, 0, 3, 1, 4}) == 6);
    assert(profit({1, 2, 3, 4, 5}) == 4);
    assert(profit({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
