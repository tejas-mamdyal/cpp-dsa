/*
 Benchmark workload 1000 elements; no timing threshold used as a correctness
assertion.

steps measures comparisons rather than elapsed time.

An absent value scans 1000 elements; the first matching value needs 1.

Each visited element increments once, matching the scan cost model.

Best O(1), worst O(n) time, O(1) work.

A single fast wall-clock result cannot establish an asymptotic bound.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

std::pair<int, int> linearFind(const std::vector<int>& a, int value) {
    int steps = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        ++steps;
        if (a[i] == value) {
            return {i, steps};
        }
    }
    return {-1, steps};
}

int main() {
    std::vector<int> a(1000, 1);
    auto [index, steps] = linearFind(a, 2);
    assert(index == -1 && steps == 1000);
    auto first = linearFind(a, 1);
    assert(first.first == 0 && first.second == 1);
    std::cout << "checks passed\n";
    return 0;
}
