/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[i][j] is LCS length of first i and j characters; increasing
rows/columns satisfy every smaller-prefix dependency.

Matching c extends the diagonal value for a to 2; matching e extends it to 3.

The match-or-skip recurrence covers every optimal final-character choice.

O(n*m) time/storage.

A mismatch does not reset LCS to 0; that is the substring recurrence.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>

std::vector<std::vector<int>> table(const std::string& a, const std::string& b) {
    std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));
    for (std::size_t i = 1; i <= a.size(); ++i) {
        for (std::size_t j = 1; j <= b.size(); ++j) {
            dp[i][j] =
                a[i - 1] == b[j - 1] ? 1 + dp[i - 1][j - 1] : std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp;
}

int main() {
    assert(table("abcde", "ace").back().back() == 3);
    assert(table("", "").back().back() == 0);
    std::cout << "checks passed\n";
    return 0;
}
