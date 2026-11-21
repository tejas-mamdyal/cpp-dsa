/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

An LPS of length L can remain unchanged while each of n-L other characters
receives a mirrored insertion.

mbadm has LPS mam or mdm of length 3, so two insertions suffice.

The interval insertion recurrence matches n-LPS: equal endpoints cost no extra;
unequal endpoints insert one mirror and solve a shorter side.

O(n^2) time/storage through the LPS baseline.

A palindromic substring is too restrictive; the retained characters may have gaps.
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

int insertions(const std::string& s) {
    return static_cast<int>(s.size()) - palindromeLength(s);
}

int main() {
    assert(insertions("mbadm") == 2);
    assert(insertions("racecar") == 0);
    assert(insertions("") == 0);
    std::cout << "checks passed\n";
    return 0;
}
