/*
 At most 30 matrices; return minimum cost and a deterministic first-split witness.

expression[l][r] stores the parenthesized product attaining dp[l][r];
strict cost improvement replaces both together.

The selected final split afterA 1 returns((A 0*A 1)*A 2).

Each saved expression combines optimal children at the split that achieved its
stored cost.

O(n^4) conservative time with copied O(n)-length expression strings, O(n^3) character
storage.

A split-index table reduces witness storage; the explicit strings prioritize beginner
readability.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <utility>
#include <limits>
#include <cstddef>

std::pair<long long, std::string> chain(const std::vector<int>& d) {
    if (d.size() < 2) {
        return {0, "EMPTY"};
    }
    int n = static_cast<int>(d.size()) - 1;
    std::vector<std::vector<long long>> dp(static_cast<std::size_t>(n),
                                           std::vector<long long>(static_cast<std::size_t>(n), 0));
    std::vector<std::vector<std::string>> expression(
        static_cast<std::size_t>(n), std::vector<std::string>(static_cast<std::size_t>(n)));
    for (int i = 0; i < n; ++i) {
        expression[i][i] = "A" + std::to_string(i);
    }
    for (int length = 2; length <= n; ++length) {
        for (int left = 0; left + length <= n; ++left) {
            int right = left + length - 1;
            dp[left][right] = std::numeric_limits<long long>::max();
            for (int split = left; split < right; ++split) {
                long long cost = dp[left][split] + dp[split + 1][right]
                                 + 1LL * d[left] * d[split + 1] * d[right + 1];
                if (cost < dp[left][right]) {
                    dp[left][right] = cost;
                    expression[left][right] =
                        "(" + expression[left][split] + "*" + expression[split + 1][right] + ")";
                }
            }
        }
    }
    return {dp[0][n - 1], expression[0][n - 1]};
}

int main() {
    auto answer = chain({10, 30, 5, 60});
    assert(answer.first == 4500 && answer.second == "((A0*A1)*A2)");
    assert(chain({10, 20}).second == "A0");
    assert(chain({}).second == "EMPTY");
    std::cout << "checks passed\n";
    return 0;
}
