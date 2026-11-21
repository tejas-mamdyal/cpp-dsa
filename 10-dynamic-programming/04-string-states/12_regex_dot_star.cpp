/*
 Lowercase text; pattern lowercase plus dot and star; malformed leading/doubled stars
return false.

dp[i][j] means full-prefix regex match; dot consumes any one character,
atom-star consumes zero copies or another matching atom.

c*a*b matches aab by zero c, two a and one b; bare a* cannot match ab.

A repeated atom is either absent or consumes a matching text character while the
same repeated atom remains available.

O(n*m) time/storage.

Reject a leading star or doubled star before reading pattern[j-2].
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

bool regex(const std::string& s, const std::string& p) {
    for (std::size_t j = 0; j < p.size(); ++j) {
        if (p[j] == '*' && (j == 0 || p[j - 1] == '*')) {
            return false;
        }
    }
    std::vector<std::vector<bool>> dp(s.size() + 1, std::vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for (std::size_t j = 2; j <= p.size(); ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    for (std::size_t i = 1; i <= s.size(); ++i) {
        for (std::size_t j = 1; j <= p.size(); ++j) {
            if (p[j - 1] == '*') {
                bool atom = p[j - 2] == '.' || p[j - 2] == s[i - 1];
                dp[i][j] = dp[i][j - 2] || (atom && dp[i - 1][j]);
            } else {
                dp[i][j] = (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
            }
        }
    }
    return dp.back().back();
}

int main() {
    assert(regex("aab", "c*a*b"));
    assert(regex("ab", ".*"));
    assert(!regex("ab", "a*"));
    assert(regex("", "a*b*"));
    assert(!regex("a", "*a"));
    std::cout << "checks passed\n";
    return 0;
}
