/*
 Rectangular binary grid<=30x 30; count all nonempty all-one squares. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

The same ending-square side s also counts exactly s squares at that
endpoint, with sides 1..s.

A 2x 2 all-one grid contributes 1+1+1+2=5 squares.

Every square has one bottom-right endpoint and one legal side no greater than
that endpoint maximum.

O(R*C) time/storage.

Adding only 1 for a positive square state misses nested smaller/larger choices.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstddef>

std::pair<int, long long> squares(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        return {0, 0};
    }
    std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(a[0].size() + 1, 0));
    int largest = 0;
    long long total = 0;
    for (std::size_t r = 1; r <= a.size(); ++r) {
        for (std::size_t c = 1; c <= a[0].size(); ++c) {
            if (a[r - 1][c - 1]) {
                dp[r][c] = 1 + std::min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]});
                largest = std::max(largest, dp[r][c]);
                total += dp[r][c];
            }
        }
    }
    return {largest, total};
}

int main() {
    assert(squares({{1, 1}, {1, 1}}).second == 5);
    assert(squares({{1, 0}, {1, 1}}).second == 3);
    std::cout << "checks passed\n";
    return 0;
}
