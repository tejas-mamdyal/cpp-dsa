/*
 n<=12 positive integers; k 1..n; partition into k nonempty equal-sum groups. Unless
narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume
valid acyclic owned structures; exponential searches use the smaller bounds stated here. No
input; keep assertions enabled. Success prints checks passed.

Sort descending and fill bucket sums without exceeding total/k. Empty
buckets are interchangeable.

4,3,2,3,5,2,1 with k 4 fits four groups of 5.

Each value must enter one bucket; capacity excludes impossible branches, while
trying one empty bucket represents all relabelings of empty buckets.

O(k^n+n log n) time, O(n+k) work.

The positivity precondition makes target positive and all target-filled buckets
nonempty.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstddef>

bool fill(const std::vector<int>& a, std::size_t i, int target, std::vector<int>& buckets) {
    if (i == a.size()) {
        return true;
    }
    for (std::size_t b = 0; b < buckets.size(); ++b) {
        if (buckets[b] + a[i] > target) {
            continue;
        }
        buckets[b] += a[i];
        bool ok = fill(a, i + 1, target, buckets);
        buckets[b] -= a[i];
        if (ok) {
            return true;
        }
        if (buckets[b] == 0) {
            break;
        }
    }
    return false;
}

bool equalGroups(std::vector<int> a, int k) {
    if (k < 1 || k > static_cast<int>(a.size())) {
        return false;
    }
    int total = 0;
    for (int x : a) {
        assert(x > 0);
        total += x;
    }
    if (total % k != 0) {
        return false;
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::vector<int> buckets(static_cast<std::size_t>(k), 0);
    return fill(a, 0, total / k, buckets);
}

int main() {
    assert(equalGroups({4, 3, 2, 3, 5, 2, 1}, 4));
    assert(!equalGroups({1, 2, 3, 4}, 3));
    assert(!equalGroups({}, 1));
    std::cout << "checks passed\n";
    return 0;
}
