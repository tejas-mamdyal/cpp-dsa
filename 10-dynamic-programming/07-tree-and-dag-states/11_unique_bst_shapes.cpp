/*
 n 0..18; Catalan counts exact in long long; keys are distinct and fixed by inorder.

dp[n] counts distinct ordered BST shapes on n fixed sorted unique keys;
root choice determines left size and right size.

For n 3, the split sizes 0+2,1+1,2+0 contribute 2+1+2=5.

Each tree has one root split; left/right shape choices are independent products,
and distinct splits are disjoint.

O(n^2) time, O(n) storage.

The empty subtree contributes 1 arrangement, not 0.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long trees(int n) {
    assert(n >= 0 && n <= 18);
    std::vector<long long> dp(static_cast<std::size_t>(n + 1), 0);
    dp[0] = 1;
    for (int size = 1; size <= n; ++size) {
        for (int left = 0; left < size; ++left) {
            dp[size] += dp[left] * dp[size - 1 - left];
        }
    }
    return dp[n];
}

int main() {
    assert(trees(0) == 1);
    assert(trees(3) == 5);
    assert(trees(5) == 42);
    std::cout << "checks passed\n";
    return 0;
}
