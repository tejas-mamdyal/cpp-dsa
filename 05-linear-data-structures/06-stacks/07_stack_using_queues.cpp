/*
BUILD LIFO BEHAVIOR FROM FIFO OPERATIONS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Two queues;push rearranges so the newest value becomes front. IDEA AND STATE:
Enqueue new value into a spare queue, move old values behind it, then swap queues. TRACE:
push1,push2 ->front2,pop ->front1. CORRECTNESS: Every push establishes newest-first queue
order; pop removes its first element. COST: Push O(n),pop/peek O(1),O(n) total storage.
PITFALL: A different tradeoff is possible; do not claim all operations are constant-time.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <queue>
#include <optional>

class QueueStack {
    std::queue<int> current;

public:
    void push(int value) {
        std::queue<int> next;
        next.push(value);
        while (!current.empty()) {
            next.push(current.front());
            current.pop();
        }
        current.swap(next);
    }

    std::optional<int> pop() {
        if (current.empty()) {
            return std::nullopt;
        }
        int value = current.front();
        current.pop();
        return value;
    }

    std::optional<int> peek() const {
        if (current.empty()) {
            return std::nullopt;
        }
        return current.front();
    }
};

int main() {
    QueueStack stack;
    assert(!stack.pop());
    stack.push(1);
    stack.push(2);
    assert(stack.pop() == 2);
    stack.push(3);
    assert(stack.peek() == 3);
    assert(stack.pop() == 3);
    assert(stack.pop() == 1);
    assert(!stack.pop());
    std::cout << "checks passed\n";
    return 0;
}
