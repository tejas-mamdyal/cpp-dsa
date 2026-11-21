/*
INTERLEAVE TWO FIFO HALVES PREREQUISITES: Phases1/2 C++ and STL, Phase3 complexity/recursion,

filenames.

 Even-length queue; empty allowed. IDEA AND STATE: Move the first half to a spare
queue,then alternately append its front and the original second-half front. TRACE: 1,2,3,4
->1,3,2,4. CORRECTNESS: Each half keeps its original order and contributes exactly one item
per pair. COST: O(n) time,O(n/2) auxiliary queue storage. PITFALL: Odd length needs a
different explicitly specified policy. PRACTICE: Change the example, predict each state update
and add an empty/boundary case. No input unless explicitly stated. Assertions are the teaching
test harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <queue>
#include <initializer_list>

void interleave(std::queue<int>& queue) {
    assert(queue.size() % 2 == 0);
    std::size_t half = queue.size() / 2;
    std::queue<int> first;
    for (std::size_t i = 0; i < half; ++i) {
        first.push(queue.front());
        queue.pop();
    }
    for (std::size_t i = 0; i < half; ++i) {
        queue.push(first.front());
        first.pop();
        queue.push(queue.front());
        queue.pop();
    }
}

int main() {
    std::queue<int> queue;
    for (int value : {1, 2, 3, 4}) {
        queue.push(value);
    }
    interleave(queue);
    for (int expected : {1, 3, 2, 4}) {
        assert(queue.front() == expected);
        queue.pop();
    }
    interleave(queue);
    assert(queue.empty());
    std::cout << "checks passed\n";
    return 0;
}
