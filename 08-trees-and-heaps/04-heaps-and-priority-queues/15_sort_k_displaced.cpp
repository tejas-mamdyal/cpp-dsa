/*
 Precondition: each item is displaced at most k positions from sorted order; k>=0.
Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples
assume valid acyclic owned structures; exponential searches use the smaller bounds stated
here. No input; keep assertions enabled. Success prints checks passed.

A min-heap of at most k+1 candidates always contains the next final value.

6,5,3,2,8,10,9 with k 3 sorts to 2,3,5,6,8,9,10.

The next minimum cannot originate more than k positions ahead; the current
frontier contains every eligible candidate.

O(n log(min(n, k+1)+1)) time, O(min(n, k+1)) heap plus output.

The displacement promise is required; this algorithm does not sort arbitrary input for
small k.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <functional>
#include <cstddef>

std::vector<int> sortNearby(const std::vector<int>& a, int k) {
    assert(k >= 0);
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    std::vector<int> out;
    for (int x : a) {
        q.push(x);
        if (q.size() > static_cast<std::size_t>(k)) {
            out.push_back(q.top());
            q.pop();
        }
    }
    while (!q.empty()) {
        out.push_back(q.top());
        q.pop();
    }
    return out;
}

int main() {
    assert((sortNearby({6, 5, 3, 2, 8, 10, 9}, 3) == std::vector<int>{2, 3, 5, 6, 8, 9, 10}));
    assert((sortNearby({1, 2}, 0) == std::vector<int>{1, 2}));
    assert(sortNearby({}, 2).empty());
    std::cout << "checks passed\n";
    return 0;
}
