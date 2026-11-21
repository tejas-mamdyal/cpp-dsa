/*
 Return next greater indices or -1; equal values are not greater.

IDEA AND STATE: Scan right to left; discard candidates no larger than the current value.

TRACE: 2,2,3 ->2,2,-1.

From the right,3 has no answer;each2 sees index2 as its next greater,while equal2 is discarded
as a candidate.

A discarded smaller candidate is blocked by a closer value at least as useful for
every earlier query.

O(n) total time, O(n) space; each index is pushed and popped at most once.

Repeated values require <= in the pop condition.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> nextGreater(const std::vector<int>& a) {
    std::vector<int> out(a.size(), -1);
    std::vector<int> stack;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        while (!stack.empty() && a[stack.back()] <= a[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) {
            out[i] = stack.back();
        }
        stack.push_back(i);
    }
    return out;
}

// Historical variant returns values rather than indices. -1 means absence and
// is ambiguous if real values can equal -1;prefer the index interface above.
std::vector<int> nextGreaterValues(const std::vector<int>& values) {
    auto indices = nextGreater(values);
    std::vector<int> out(values.size(), -1);
    for (std::size_t i = 0; i < indices.size(); ++i) {
        if (indices[i] != -1) {
            out[i] = values[static_cast<std::size_t>(indices[i])];
        }
    }
    return out;
}

int main() {
    assert((nextGreaterValues({2, 1, 3, 3}) == std::vector<int>{3, 3, -1, -1}));
    assert((nextGreater({2, 2, 3}) == std::vector<int>{2, 2, -1}));
    assert(nextGreater({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
