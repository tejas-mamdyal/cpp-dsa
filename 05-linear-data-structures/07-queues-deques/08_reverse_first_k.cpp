/*
REVERSE ONLY A QUEUE PREFIX PREREQUISITES: Phases1/2 C++ and STL, Phase3 complexity/recursion,

filenames.

 0<=k<=size; invalid k returns false without mutation. IDEA AND STATE: Pop k items
onto a stack,append them reversed,then rotate the untouched suffix behind them. TRACE: 1,2,3,4
with k3 ->3,2,1,4. CORRECTNESS: The stack reverses exactly the selected prefix; rotating the
suffix restores the desired concatenation. COST: O(n) time,O(k) extra space; k0 may return
immediately. PITFALL: Validate k before popping any item. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
#include <initializer_list>

bool reverseFirst(std::queue<int>& queue, std::size_t k) {
    std::size_t n = queue.size();
    if (k > n) {
        return false;
    }
    if (k == 0) {
        return true;
    }
    std::stack<int> stack;
    for (std::size_t i = 0; i < k; ++i) {
        stack.push(queue.front());
        queue.pop();
    }
    while (!stack.empty()) {
        queue.push(stack.top());
        stack.pop();
    }
    for (std::size_t i = 0; i < n - k; ++i) {
        queue.push(queue.front());
        queue.pop();
    }
    return true;
}

int main() {
    std::queue<int> queue;
    for (int value : {1, 2, 3, 4}) {
        queue.push(value);
    }
    assert(!reverseFirst(queue, 5));
    assert(queue.front() == 1);
    assert(reverseFirst(queue, 3));
    for (int expected : {3, 2, 1, 4}) {
        assert(queue.front() == expected);
        queue.pop();
    }
    assert(reverseFirst(queue, 0));
    std::cout << "checks passed\n";
    return 0;
}
