/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[i][j] is minimum edits converting first i source characters to first j
target characters; empty-prefix costs are i or j.

horse to ros uses three edits; empty source to abc needs three insertions.

The final alignment matches equal ends for free or applies one of deletion,
insertion, replacement to an optimal shorter-prefix conversion.

O(n*m) time/storage.

Omitting empty-prefix initialization makes insertion/deletion boundaries falsely
free.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>

int edits(const std::string& a, const std::string& b) {
    std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));
    for (std::size_t i = 0; i <= a.size(); ++i) {
        dp[i][0] = static_cast<int>(i);
    }
    for (std::size_t j = 0; j <= b.size(); ++j) {
        dp[0][j] = static_cast<int>(j);
    }
    for (std::size_t i = 1; i <= a.size(); ++i) {
        for (std::size_t j = 1; j <= b.size(); ++j) {
            dp[i][j] = a[i - 1] == b[j - 1]
                           ? dp[i - 1][j - 1]
                           : 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    return dp.back().back();
}

int main() {
    assert(edits("horse", "ros") == 3);
    assert(edits("", "abc") == 3);
    assert(edits("same", "same") == 0);
    std::cout << "checks passed\n";
    return 0;
}
