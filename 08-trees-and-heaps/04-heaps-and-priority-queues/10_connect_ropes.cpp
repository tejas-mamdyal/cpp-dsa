/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Nonnegative lengths; cost of a merge is its total length; repeat until one
remains.

4,3,2,6 merges 2+3=5, then 4+5=9, then 6+9=15, total 29.

In an optimal binary merge tree, the two smallest weights can be exchanged into
deepest sibling leaves without increasing weighted path cost; contracting them reduces to the
same problem.

O(n log(n+1)) time, O(n) heap.

Accumulated cost needs long long; this is not ordinary sorted concatenation.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <functional>

long long cost(const std::vector<int>& a) {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q;
    for (int x : a) {
        assert(x >= 0);
        q.push(x);
    }
    long long total = 0;
    while (q.size() > 1) {
        long long first = q.top();
        q.pop();
        long long second = q.top();
        q.pop();
        long long sum = first + second;
        total += sum;
        q.push(sum);
    }
    return total;
}

int main() {
    assert(cost({4, 3, 2, 6}) == 29);
    assert(cost({}) == 0);
    assert(cost({7}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
