/*
 10000-element input and 100 repetitions; no performance pass/fail threshold. Unless
a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

steady_clock measures an interval; the observed checksum keeps correctness
tied to the repeated workload.

100 sums of 30000 yield 3000000.

Every repeated call is checked against the arithmetic expected total.

O(repetitions*n) work, O(n) input.

This small demonstration may be optimized aggressively; real comparisons need
representative workloads and optimized-build reporting.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

long long direct(const std::vector<int>& a) {
    long long result = 0;
    for (int x : a) {
        result += x;
    }
    return result;
}

int main() {
    std::vector<int> a(10000, 3);
    assert(direct(a) == 30000);
    auto start = std::chrono::steady_clock::now();
    long long checksum = 0;
    for (int repeat = 0; repeat < 100; ++repeat) {
        checksum += direct(a);
    }
    auto end = std::chrono::steady_clock::now();
    assert(checksum == 3000000);
    assert(end >= start);
    std::cout << "checks passed\n";
    return 0;
}
