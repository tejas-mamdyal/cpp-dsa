/*
 Binary array; return longest interval with equal zero and one counts.

IDEA AND STATE: Map 0 to-1 and 1 to+1, then retain the first position of each balance.

TRACE: 0,1,0 ->2;0,0,1,1 ->4.

Balances for0,1,0 are -1,0,-1;balance0 repeats the initial position to give length2.

Equal prefix balances imply equal numbers of both categories in the difference
range.

Expected O(n) time, O(n) space.

The transformation depends on exactly two categories and a declared mapping.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>

int balanced(const std::vector<int>& a) {
    std::unordered_map<int, int> first;
    first.emplace(0, -1);
    int balance = 0;
    int best = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        assert(a[i] == 0 || a[i] == 1);
        if (a[i] == 0) {
            --balance;
        } else {
            ++balance;
        }
        auto it = first.find(balance);
        if (it != first.end()) {
            best = std::max(best, i - it->second);
        } else {
            first.emplace(balance, i);
        }
    }
    return best;
}

int main() {
    assert(balanced({0, 1, 0}) == 2);
    assert(balanced({0, 0, 1, 1}) == 4);
    assert(balanced({1, 1}) == 0);
    assert(balanced({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
