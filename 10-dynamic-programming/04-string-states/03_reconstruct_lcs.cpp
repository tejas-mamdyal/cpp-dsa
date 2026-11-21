/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

Start at dp[n][m], append matched final characters backward; on a mismatch
follow a predecessor with equal optimum length.

abcde versus ace records e, c, a backward, then reverses to ace.

Each selected backward transition preserves the remaining optimum and matched
characters appear in both strings in order.

O(n*m) table/time plus O(n+m) traceback.

Length alone does not identify a unique LCS; state a deterministic local tie policy.
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

std::string lcs(const std::string& a, const std::string& b) {
    auto dp = table(a, b);
    std::size_t i = a.size();
    std::size_t j = b.size();
    std::string out;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            out.push_back(a[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    assert(lcs("abcde", "ace") == "ace");
    assert(lcs("abc", "def").empty());
    assert(lcs("", "").empty());
    std::cout << "checks passed\n";
    return 0;
}
