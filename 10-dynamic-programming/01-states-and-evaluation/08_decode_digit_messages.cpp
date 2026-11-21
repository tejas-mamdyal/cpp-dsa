/*
 Digit-only string, length<=30; empty text has one empty decoding. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

dp[i] counts decodings of the first i digits using codes 1..26; empty
prefix has one decoding.

226 yields 2-2-6,22-6 and 2-26;06 has no legal leading code.

The final code has length 1 or 2; legal final codes combine with all decodings of
the corresponding earlier prefix.

O(n) time, O(n) table.

A single 0 is invalid while 10 and 20 are valid pairs.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

long long decode(const std::string& s) {
    std::vector<long long> dp(s.size() + 1, 0);
    dp[0] = 1;
    for (std::size_t i = 1; i <= s.size(); ++i) {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        if (i >= 2) {
            int value = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (value >= 10 && value <= 26) {
                dp[i] += dp[i - 2];
            }
        }
    }
    return dp.back();
}

int main() {
    assert(decode("226") == 3);
    assert(decode("06") == 0);
    assert(decode("10") == 1);
    assert(decode("") == 1);
    std::cout << "checks passed\n";
    return 0;
}
