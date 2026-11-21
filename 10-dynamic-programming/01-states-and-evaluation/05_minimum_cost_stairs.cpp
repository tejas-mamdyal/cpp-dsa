/*
 Nonnegative costs; at most 30 steps; start at step 0 or 1, climb 1/2 positions to
index n.

dp[i] is minimum cost to stand just beyond step i-1; dp 0=dp 1=0 because
starting on either first step is allowed.

Costs 10,15,20 give dp 2=10 and dp 3=min(10+20,0+15)=15.

The final move comes from one or two positions earlier and pays the departure
step cost.

O(n) time, O(1) auxiliary.

State whether a cost is paid on arrival or departure before deriving indices.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

long long minimumCost(const std::vector<int>& cost) {
    long long two = 0;
    long long one = 0;
    for (std::size_t i = 2; i <= cost.size(); ++i) {
        long long next = std::min(one + cost[i - 1], two + cost[i - 2]);
        two = one;
        one = next;
    }
    return one;
}

int main() {
    assert(minimumCost({10, 15, 20}) == 15);
    assert(minimumCost({}) == 0);
    assert(minimumCost({5}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
