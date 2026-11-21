/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[left][right] is LPS length contained in the inclusive substring
interval; shorter intervals are dependencies.

bbbab can retain bbbb as a subsequence of length 4 despite the internal a.

Equal endpoints can enclose an optimal inner palindrome; otherwise an optimum
omits at least one unequal endpoint.

O(n^2) time/storage.

This is an interval state, not a prefix state; increasing interval length supplies
its dependency order.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

int palindromeLength(const std::string& s) {
    if (s.empty()) {
        return 0;
    }
    int n = static_cast<int>(s.size());
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    for (int length = 2; length <= n; ++length) {
        for (int left = 0; left + length <= n; ++left) {
            int right = left + length - 1;
            if (s[left] == s[right]) {
                dp[left][right] = 2 + (length == 2 ? 0 : dp[left + 1][right - 1]);
            } else {
                dp[left][right] = std::max(dp[left + 1][right], dp[left][right - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    assert(palindromeLength("bbbab") == 4);
    assert(palindromeLength("cbbd") == 2);
    assert(palindromeLength("") == 0);
    std::cout << "checks passed\n";
    return 0;
}
