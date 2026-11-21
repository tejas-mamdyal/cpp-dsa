/*
 At most 30 positive integers; duplicates are positional copies and may coexist in a
chain.

dp[i] is the largest divisible chain ending at sorted a[i]; parent records
its chosen predecessor.

1 divides 2,2 divides 4,4 divides 8; transitivity makes every earlier-later pair
divisible.

Positive sorted divisibility is transitive; every valid chain has a
smaller-or-equal divisible predecessor.

O(n^2+n log n) time, O(n) states/copy.

Zero cannot be used as a divisor in this implementation.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> divisible(std::vector<int> a) {
    if (a.empty()) {
        return {};
    }
    std::sort(a.begin(), a.end());
    std::vector<int> dp(a.size(), 1);
    std::vector<int> parent(a.size(), -1);
    int best = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        assert(a[i] > 0);
        for (int j = 0; j < i; ++j) {
            if (a[i] % a[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > dp[best]) {
            best = i;
        }
    }
    std::vector<int> out;
    for (int i = best; i != -1; i = parent[i]) {
        out.push_back(a[i]);
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    assert((divisible({1, 2, 4, 8}) == std::vector<int>{1, 2, 4, 8}));
    assert(divisible({1, 2, 3}).size() == 2);
    assert(divisible({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
