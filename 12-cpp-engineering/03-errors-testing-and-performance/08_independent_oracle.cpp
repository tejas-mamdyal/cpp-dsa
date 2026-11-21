/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

The optimized scan counts prior equal values; the oracle enumerates pairs
directly.

[1,1,1] produces prior counts 0+1+2=3.

Every equal pair is counted once at its later endpoint.

Fast O(n log n), oracle O(n^2), O(n) map storage.

An oracle copied from the same recurrence may repeat the same bug.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <cstddef>

long long fast(const std::vector<int>& a) {
    long long count = 0;
    std::map<int, int> seen;
    for (int x : a) {
        count += seen[x];
        ++seen[x];
    }
    return count;
}

long long reference(const std::vector<int>& a) {
    long long count = 0;
    for (std::size_t i = 0; i < a.size(); ++i) {
        for (std::size_t j = i + 1; j < a.size(); ++j) {
            count += a[i] == a[j];
        }
    }
    return count;
}

int main() {
    for (int mask = 0; mask < 243; ++mask) {
        std::vector<int> a(5);
        int digits = mask;
        for (int& x : a) {
            x = digits % 3;
            digits /= 3;
        }
        assert(fast(a) == reference(a));
    }
    std::cout << "checks passed\n";
    return 0;
}
