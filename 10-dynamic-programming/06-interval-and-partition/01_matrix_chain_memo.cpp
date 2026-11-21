/*
 At most 30 matrices; positive dimensions<=1000; empty/one matrix cost 0. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

f(left, right) is minimum scalar multiplications for matrices left..right;
matrix i has dimensions d[i] by d[i+1].

Multiply 10x 30 with 30x 5 for 1500, then 10x 5 with 5x 60 for 3000, total 4500.

Every parenthesization has one final split; its two optimal subproducts combine
with the fixed outer dimension multiplication cost.

O(n^3) time, O(n^2) memo plus O(n) recursion.

Using d[split] instead of d[split+1] mismatches matrix dimensions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstddef>

long long
solve(const std::vector<int>& d, int left, int right, std::vector<std::vector<long long>>& memo) {
    if (left == right) {
        return 0;
    }
    if (memo[left][right] != -1) {
        return memo[left][right];
    }
    long long best = std::numeric_limits<long long>::max();
    for (int split = left; split < right; ++split) {
        long long cost = solve(d, left, split, memo) + solve(d, split + 1, right, memo)
                         + 1LL * d[left] * d[split + 1] * d[right + 1];
        best = std::min(best, cost);
    }
    memo[left][right] = best;
    return best;
}

long long matrixCost(const std::vector<int>& d) {
    if (d.size() < 2) {
        return 0;
    }
    int n = static_cast<int>(d.size()) - 1;
    std::vector<std::vector<long long>> memo(
        static_cast<std::size_t>(n), std::vector<long long>(static_cast<std::size_t>(n), -1));
    return solve(d, 0, n - 1, memo);
}

int main() {
    assert(matrixCost({10, 30, 5, 60}) == 4500);
    assert(matrixCost({10, 20}) == 0);
    assert(matrixCost({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
