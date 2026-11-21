/*
 Nonnegative heights.

The stack stores nondecreasing bar heights; pop finalizes the maximal span
for a limiting height.

Height 5 spans the adjacent 5,6 bars and yields 10.

The smaller boundaries exclude every wider rectangle using that height; every
optimum has a limiting bar.

O(n) time, O(n) stack.

Width excludes both smaller boundaries; equal bars remain valid candidates.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int area(const std::vector<int>& a) {
    std::vector<int> stack;
    int best = 0;
    for (int i = 0; i <= static_cast<int>(a.size()); ++i) {
        int current = i == static_cast<int>(a.size()) ? 0 : a[i];
        while (!stack.empty() && a[stack.back()] > current) {
            int height = a[stack.back()];
            stack.pop_back();
            int left = stack.empty() ? -1 : stack.back();
            best = std::max(best, height * (i - left - 1));
        }
        stack.push_back(i);
    }
    return best;
}

int main() {
    assert(area({2, 1, 5, 6, 2, 3}) == 10);
    assert(area({2, 2}) == 4);
    assert(area({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
