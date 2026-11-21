/*
 Return closest strictly smaller left index or -1.

IDEA AND STATE: Left-to-right increasing stack; pop >= current.

TRACE: 3,1,2 ->-1,-1,1.

Read3 with empty stack;1 pops3;2 then sees index1 with value1 as its previous smaller.

After dominated candidates leave, the top is the nearest remaining smaller value.

O(n) total time, O(n) space.

Direction chooses previous versus next; stack order alone does not.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> previous(const std::vector<int>& a) {
    std::vector<int> out(a.size(), -1);
    std::vector<int> stack;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
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
    assert((previous({3, 1, 2}) == std::vector<int>{-1, -1, 1}));
    assert((previous({2, 2}) == std::vector<int>{-1, -1}));
    std::cout << "checks passed\n";
    return 0;
}
