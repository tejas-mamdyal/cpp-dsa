/*
 Teaching oracle limited to n<=5, values 0..2; positive group limit.

IDEA AND STATE: Enumerate cuts between neighbors independently, then compare the smallest legal
maximum against binary search.

TRACE: All arrays through length 5 and every k 1..n+1 are compared.

For each array,enumerate every between-element cut mask;minimize worst group sum among masks
using at most k groups.

Every contiguous partition corresponds to one cut mask; exhaustion provides an
independent finite-domain reference.

Optimized O(n log(S+1)); oracle O(n*2^n), only for tiny tests.

Agreement on finite tests supports correctness but does not replace the greedy and
monotonicity proofs.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <limits>

bool canSplitWork(const std::vector<int>& tasks, int groups, long long capacity) {
    if (groups < 1 || capacity < 0) {
        return false;
    }
    int used = 1;
    long long load = 0;
    for (int task : tasks) {
        assert(task >= 0);
        if (task > capacity) {
            return false;
        }
        if (load + task > capacity) {
            ++used;
            load = 0;
        }
        load += task;
    }
    return used <= groups;
}

std::optional<long long> split(const std::vector<int>& a, int k) {
    if (k < 1) {
        return std::nullopt;
    }
    long long low = 0;
    long long high = 0;
    for (int x : a) {
        assert(x >= 0);
        low = std::max(low, 1LL * x);
        high += x;
    }
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canSplitWork(a, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

long long brute(const std::vector<int>& a, int k) {
    if (a.empty()) {
        return 0;
    }
    int n = static_cast<int>(a.size());
    long long best = std::numeric_limits<long long>::max();
    for (unsigned int mask = 0; mask < (1U << (n - 1)); ++mask) {
        int groups = 1;
        long long load = a[0];
        long long worst = 0;
        for (int i = 1; i < n; ++i) {
            if ((mask & (1U << (i - 1))) != 0U) {
                worst = std::max(worst, load);
                load = 0;
                ++groups;
            }
            load += a[i];
        }
        worst = std::max(worst, load);
        if (groups <= k) {
            best = std::min(best, worst);
        }
    }
    return best;
}

int main() {
    for (int n = 0; n <= 5; ++n) {
        int cases = 1;
        for (int i = 0; i < n; ++i) {
            cases *= 3;
        }
        for (int code = 0; code < cases; ++code) {
            std::vector<int> a(static_cast<std::size_t>(n));
            int value = code;
            for (int& x : a) {
                x = value % 3;
                value /= 3;
            }
            for (int k = 1; k <= n + 1; ++k) {
                assert(split(a, k) == brute(a, k));
            }
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
