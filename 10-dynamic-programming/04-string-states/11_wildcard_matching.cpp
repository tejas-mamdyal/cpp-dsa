/*
 Lowercase text; pattern lowercase plus? and*; full-string matching. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[i][j] means the first i text characters fully match first j pattern
characters;? matches one and* matches any length.

*a*b can skip the first star, match a, let the next star absorb dce, and match b.

A star either consumes nothing or consumes one text character and stays active;
other atoms consume one matching character.

O(n*m) time/storage.

This wildcard star is not regex repetition of the preceding atom.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

bool wildcard(const std::string& s, const std::string& p) {
    std::vector<std::vector<bool>> dp(s.size() + 1, std::vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for (std::size_t j = 1; j <= p.size(); ++j) {
        dp[0][j] = p[j - 1] == '*' && dp[0][j - 1];
    }
    for (std::size_t i = 1; i <= s.size(); ++i) {
        for (std::size_t j = 1; j <= p.size(); ++j) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else {
                dp[i][j] = (p[j - 1] == '?' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
            }
        }
    }
    return dp.back().back();
}

int main() {
    assert(wildcard("adceb", "*a*b"));
    assert(!wildcard("acdcb", "a*c?b"));
    assert(wildcard("", "**"));
    std::cout << "checks passed\n";
    return 0;
}
