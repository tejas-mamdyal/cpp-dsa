/*
 Nonnegative prices; unlimited transactions, one share maximum, one action per day.

cash is best profit ending a day without a share; hold is best balance
ending with one share. Read previous-day states for both transitions.

Buy 1, sell 5, buy 3, sell 6 returns 4+3=7.

A cash-ending history rests or sells; holding rests or buys from a cash-ending
history. These cover all legal histories.

O(n) time, O(1) auxiliary.

Returning hold permits an unfinished purchase; final answer is cash.
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
        long long nextHold = std::max(hold, cash - p);
        cash = nextCash;
        hold = nextHold;
    }
    return cash;
}

int main() {
    assert(profit({7, 1, 5, 3, 6, 4}) == 7);
    assert(profit({1, 2, 3}) == 2);
    assert(profit({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
