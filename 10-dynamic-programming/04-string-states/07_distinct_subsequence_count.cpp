/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[j] counts index selections from processed source forming the first j
target characters; empty target has one selection.

Three source a positions choose any two for target aa, total 3.

Each source character is skipped or used once as the next matching target
character; descending j preserves single use.

O(n*m) time, O(m) auxiliary; source length<=30 keeps exact counts within 2^30.

Ascending target updates could use the same source character more than once.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

long long distinct(const std::string& source, const std::string& target) {
    std::vector<long long> dp(target.size() + 1, 0);
    dp[0] = 1;
    for (char ch : source) {
        for (std::size_t j = target.size(); j > 0; --j) {
            if (ch == target[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp.back();
}

int main() {
    assert(distinct("rabbbit", "rabbit") == 3);
    assert(distinct("", "") == 1);
    assert(distinct("aaa", "aa") == 3);
    std::cout << "checks passed\n";
    return 0;
}
