/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A max-heap requires every parent>=child; a min-heap reverses that
inequality.

9,7,8,1,2 is max-heap but not a sorted vector;9,10 fails at child 1.

Checking each nonroot edge covers every heap inequality once.

O(n) validation time, O(1) auxiliary.

A heap only promises an extreme at the root, not arbitrary sorted positions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

bool maxHeap(const std::vector<int>& a) {
    for (std::size_t i = 1; i < a.size(); ++i) {
        if (a[(i - 1) / 2] < a[i]) {
            return false;
        }
    }
    return true;
}

bool minHeap(const std::vector<int>& a) {
    for (std::size_t i = 1; i < a.size(); ++i) {
        if (a[(i - 1) / 2] > a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(maxHeap({9, 7, 8, 1, 2}));
    assert(!maxHeap({9, 10}));
    assert(minHeap({1, 2, 3}));
    assert(maxHeap({}) && minHeap({}));
    std::cout << "checks passed\n";
    return 0;
}
