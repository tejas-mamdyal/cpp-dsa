/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Leaves already satisfy heap order; repair parents from the last internal
node toward root.

Input 1,2,3 first repairs parent 0 or its descendants until root 3 is maximal.

When repairing a node, both child subtrees are already heaps; downward repair
establishes its whole subtree.

O(n) time because at most n/2^(h+1) nodes move h levels; O(1) auxiliary.

Repeated push is O(n log n); bottom-up build uses a different aggregate bound.
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

int main() {
    for (auto a : std::vector<std::vector<int>>{{}, {1}, {1, 2, 3}, {4, 1, 4, -2, 9}}) {
        build(a);
        assert(std::is_heap(a.begin(), a.end()));
    }
    std::cout << "checks passed\n";
    return 0;
}
