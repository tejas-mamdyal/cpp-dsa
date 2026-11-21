/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

The heap retains the best k seen values; its minimum is the kth largest.
Invalid k gives absence; duplicates count individually.

3,2,1,5,6,4 with k 2 retains 5,6 and returns 5.

A new value smaller than the heap minimum cannot enter the best k; larger values
replace the current worst retained candidate.

O(n log(k+1)) time, O(k) space.

Do not confuse kth largest element with kth distinct value.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <queue>
#include <functional>

std::optional<int> kthLargest(const std::vector<int>& a, int k) {
    if (k < 1 || k > static_cast<int>(a.size())) {
        return std::nullopt;
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int x : a) {
        q.push(x);
        if (static_cast<int>(q.size()) > k) {
            q.pop();
        }
    }
    return q.top();
}

int main() {
    assert(kthLargest({3, 2, 1, 5, 6, 4}, 2) == 5);
    assert(kthLargest({5, 5, 2}, 2) == 5);
    assert(!kthLargest({}, 1));
    std::cout << "checks passed\n";
    return 0;
}
