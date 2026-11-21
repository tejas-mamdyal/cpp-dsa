/*
CHECK A FORMULA AGAINST AN INDEPENDENT BASELINE
Route: Reinforcement | Prerequisites: Units 01–07; functions and input validation.

Two independent derivations should agree on small cases. assert stops a debug build at
the first violated programmer assumption.

O(N^2) total time for checking every n through N, O(1) space; here N=100.

Assertions can be disabled with NDEBUG. Do not use assert as external input validation.
*/
#include <iostream>
#include <cassert>

int main() {
    for (int n = 0; n <= 100; ++n) {
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i;
        }
        long long formula = 1LL * n * (n + 1) / 2;
        assert(sum == formula); // Independent small-case oracle comparison.
    }
    std::cout << "checks passed\n";
}
