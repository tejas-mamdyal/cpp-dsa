/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Build max-heap; exchange root with the last unsorted slot; repair only the
remaining prefix.

3,1,2 places 3 at the end, then 2, leaving ascending 1,2,3.

Root is the maximum of the unsorted prefix; placing it before the already larger
suffix preserves final order.

O(n log(n+1)) time, O(1) auxiliary, in-place but not stable.

Passing full size to sift would mix already finalized suffix values back into the
heap.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstddef>

void sift(std::vector<int>& a, std::size_t root, std::size_t size) {
    while (2 * root + 1 < size) {
        std::size_t child = 2 * root + 1;
        if (child + 1 < size && a[child + 1] > a[child]) {
            ++child;
        }
        if (a[root] >= a[child]) {
            break;
        }
        std::swap(a[root], a[child]); // Move the higher-priority child toward the heap root.
        root = child;
    }
}

void build(std::vector<int>& a) {
    for (std::size_t i = a.size() / 2; i > 0; --i) {
        sift(a, i - 1, a.size());
    }
}

void heapSort(std::vector<int>& a) {
    build(a);
    for (std::size_t size = a.size(); size > 1; --size) {
        std::swap(a[0], a[size - 1]);
        sift(a, 0, size - 1);
    }
}

int main() {
    for (auto a : std::vector<std::vector<int>>{{}, {1}, {3, 1, 2}, {4, -1, 4, 0}}) {
        auto expected = a;
        std::sort(expected.begin(), expected.end());
        heapSort(a);
        assert(a == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
