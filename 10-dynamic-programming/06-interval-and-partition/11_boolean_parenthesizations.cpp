/*
 At most 15 T/F operands; exactly n-1 operators from&,|,^; empty has 0 expressions.

dp[l][r][truth] counts binary parenthesizations of operands l..r producing
that truth value; try each final operator split.

T^F&T is true under both(T^F)&T and T^(F&T), so count 2.

Every parenthesization has one final split; independent child outcome counts
multiply, and disjoint splits add.

O(n^3) time, O(n^2) storage; operand count<=15 keeps exact counts safe.

Discarding false-child counts loses ways where a parent operator turns false operands
into a true result.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <array>

long long trueWays(const std::string& values, const std::string& operations) {
    int n = static_cast<int>(values.size());
    if (n == 0) {
        return 0;
    }
    assert(operations.size() + 1 == values.size());
    using Counts = std::array<long long, 2>;
    std::vector<std::vector<Counts>> dp(values.size(),
                                        std::vector<Counts>(values.size(), Counts{0, 0}));
    for (int i = 0; i < n; ++i) {
        dp[i][i][values[i] == 'T' ? 1 : 0] = 1;
    }
    for (int length = 2; length <= n; ++length) {
        for (int l = 0; l + length <= n; ++l) {
            int r = l + length - 1;
            for (int split = l; split < r; ++split) {
                for (int a = 0; a < 2; ++a) {
                    for (int b = 0; b < 2; ++b) {
                        char op = operations[split];
                        int result = op == '&' ? (a && b) : op == '|' ? (a || b) : (a != b);
                        dp[l][r][result] += dp[l][split][a] * dp[split + 1][r][b];
                    }
                }
            }
        }
    }
    return dp[0][n - 1][1];
}

int main() {
    assert(trueWays("TFT", "^&") == 2);
    assert(trueWays("F", "") == 0);
    assert(trueWays("", "") == 0);
    std::cout << "checks passed\n";
    return 0;
}
