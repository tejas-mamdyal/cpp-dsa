/*
REVERSE A STACK USING RECURSIVE BOTTOM INSERTION PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Vector back represents top; at most20 elements. IDEA AND STATE: Pop top, reverse the
smaller stack, then insert the old top at its bottom. TRACE: bottom-to-top1,2,3 becomes3,2,1.
CORRECTNESS: The recursive reverse orders the smaller stack and bottom insertion places the
removed top in its final position. COST: O(n^2) time,O(n) call stack. PITFALL: It is not
linear: each bottom insertion traverses the current stack. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void insertBottom(std::vector<int>& stack, int value) {
    if (stack.empty()) {
        stack.push_back(value);
        return;
    }
    int top = stack.back();
    stack.pop_back();
    insertBottom(stack, value);
    stack.push_back(top);
}

void reverseStack(std::vector<int>& stack) {
    if (stack.empty()) {
        return;
    }
    int top = stack.back();
    stack.pop_back();
    reverseStack(stack);
    insertBottom(stack, top);
}

int main() {
    for (int n = 0; n <= 10; ++n) {
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(i);
        }
        auto expected = a;
        std::reverse(expected.begin(), expected.end());
        reverseStack(a);
        assert(a == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
