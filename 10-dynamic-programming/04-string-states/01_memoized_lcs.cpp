/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

f(i, j) is longest common subsequence length in a[i..n), b[j..m); an
exhausted suffix gives 0.

Matching a advances both suffixes; after skipping b and d, the route finds ace.

Equal leading characters can extend an optimal shared suffix; otherwise an
optimum skips at least one unequal leading character.

O(n*m) time/table, O(n+m) recursion.

Cache both indices; one index alone does not identify the unresolved problem.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>

int solve(const std::string& a,
          const std::string& b,
          std::size_t i,
          std::size_t j,
          std::vector<std::vector<int>>& memo) {
    if (i == a.size() || j == b.size()) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (a[i] == b[j]) {
        memo[i][j] = 1 + solve(a, b, i + 1, j + 1, memo);
    } else {
        memo[i][j] = std::max(solve(a, b, i + 1, j, memo), solve(a, b, i, j + 1, memo));
    }
    return memo[i][j];
}

int lcs(const std::string& a, const std::string& b) {
    std::vector<std::vector<int>> memo(a.size(), std::vector<int>(b.size(), -1));
    return solve(a, b, 0, 0, memo);
}

int main() {
    assert(lcs("abcde", "ace") == 3);
    assert(lcs("", "abc") == 0);
    assert(lcs("abc", "def") == 0);
    std::cout << "checks passed\n";
    return 0;
}
