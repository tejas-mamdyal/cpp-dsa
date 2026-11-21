/*
 n 0..60; counts fit long long.

memo[r] stores completed f(r), or-1 when unknown; nonnegative counts
make-1 an unambiguous sentinel.

When f 3 is requested the second time, it returns its saved value 3 without
visiting its children.

The recurrence is unchanged; returning a previously computed identical state
preserves its mathematical answer.

O(n) time, O(n) memo and recursion.

A cache must be shared by reference across calls rather than copied.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

long long solve(int n, std::vector<long long>& memo) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    return memo[n];
}

long long ways(int n) {
    assert(n >= 0 && n <= 60);
    std::vector<long long> memo(static_cast<std::size_t>(n + 1), -1);
    return solve(n, memo);
}

int main() {
    assert(ways(5) == 8);
    assert(ways(0) == 1);
    assert(ways(10) == 89);
    std::cout << "checks passed\n";
    return 0;
}
