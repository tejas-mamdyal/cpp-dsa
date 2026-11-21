/*
 Return next greater values circularly or -1; values nonnegative.

IDEA AND STATE: Resolve waiting indices while scanning 2n positions; push only in the first
pass.

TRACE: 1,2,1 ->2,-1,2.

First pass resolves index0 when2 arrives;second-pass2 resolves the trailing1,while2 itself
remains unanswered.

The second pass exposes wraparound candidates; strict comparisons cannot match an
index to itself.

O(n) time, O(n) space.

Empty input must avoid modulo zero; the loop then performs no iterations.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> circularNext(const std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    std::vector<int> out(a.size(), -1);
    std::vector<int> stack;
    for (int step = 0; step < 2 * n; ++step) {
        int i = step % n;
        while (!stack.empty() && a[stack.back()] < a[i]) {
            out[stack.back()] = a[i];
            stack.pop_back();
        }
        if (step < n) {
            stack.push_back(i);
        }
    }
    return out;
}

int main() {
    assert((circularNext({1, 2, 1}) == std::vector<int>{2, -1, 2}));
    assert(circularNext({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
