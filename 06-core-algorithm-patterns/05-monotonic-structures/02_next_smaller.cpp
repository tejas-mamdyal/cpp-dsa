/*
 Return next strictly smaller indices or -1.

IDEA AND STATE: Right-to-left stack removes values >= current.

TRACE: 3,1,1,0 ->1,3,3,-1.

From the right,0 remains the next smaller for both1 values;3 then sees the closer1 at index1.

A closer no-larger value dominates the removed candidate for earlier smaller
queries.

O(n) amortized time, O(n) space.

Changing strictness changes duplicate answers.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> nextSmaller(const std::vector<int>& a) {
    std::vector<int> out(a.size(), -1);
    std::vector<int> stack;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        while (!stack.empty() && a[stack.back()] >= a[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) {
            out[i] = stack.back();
        }
        stack.push_back(i);
    }
    return out;
}

int main() {
    assert((nextSmaller({3, 1, 1, 0}) == std::vector<int>{1, 3, 3, -1}));
    assert(nextSmaller({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
