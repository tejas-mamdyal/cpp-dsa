/*
 Nonnegative unit-width bar heights; empty area 0.

IDEA AND STATE: When a smaller bar arrives, pop and use the remaining top as the exclusive left
boundary.

TRACE: 2,1,5,6,2,3 ->10.

When height2 follows6,pop6 with width1,then5 with width2;area10 is retained.

Each popped bar spans all currently possible bars at least its height; every
maximum has some limiting bar.

O(n) total time, O(n) stack space.

Width is right-left-1; the sentinel flushes but must never become an indexed bar.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long histogram(const std::vector<int>& h) {
    std::vector<int> stack;
    long long best = 0;
    int n = static_cast<int>(h.size());
    for (int i = 0; i <= n; ++i) {
        int height = i == n ? 0 : h[i];
        while (!stack.empty() && h[stack.back()] >= height) {
            int top = stack.back();
            stack.pop_back();
            int left = stack.empty() ? -1 : stack.back();
            best = std::max(best, 1LL * h[top] * (i - left - 1));
        }
        if (i < n) {
            stack.push_back(i);
        }
    }
    return best;
}

int main() {
    assert(histogram({2, 1, 5, 6, 2, 3}) == 10);
    assert(histogram({2, 2}) == 4);
    assert(histogram({}) == 0);
    assert(histogram({0, 0}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
