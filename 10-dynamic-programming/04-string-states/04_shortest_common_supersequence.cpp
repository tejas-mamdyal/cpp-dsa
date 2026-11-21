/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

Use the LCS table to choose shared characters once and unmatched
characters from their own string.

abac and cab share ab; merging remaining c and ac produces cabac, length 5=4+3-2.

Every shared subsequence saves one output position per shared character;
maximizing that saving with LCS minimizes total length.

O(n*m) time/storage plus O(n+m) output.

Both original strings must remain subsequences of the result, not necessarily
substrings.
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

std::string supersequence(const std::string& a, const std::string& b) {
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
            out.push_back(a[i - 1]);
            --i;
        } else {
            out.push_back(b[j - 1]);
            --j;
        }
    }
    while (i > 0) {
        --i;
        out.push_back(a[i]);
    }
    while (j > 0) {
        --j;
        out.push_back(b[j]);
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    auto s = supersequence("abac", "cab");
    assert(s == "cabac");
    assert(supersequence("", "abc") == "abc");
    std::cout << "checks passed\n";
    return 0;
}
