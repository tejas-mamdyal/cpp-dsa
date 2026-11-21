/*
TWO STACKS GIVE AMORTIZED FIFO BEHAVIOR PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 enqueue,front,pop; optional absence when empty. IDEA AND STATE: Push into incoming;
transfer to outgoing only when outgoing is empty. TRACE: enqueue1,2;pop1;enqueue3;next
remains2. CORRECTNESS: Reversing incoming exposes its earliest item; old outgoing items must
leave before newer incoming ones. COST: Amortized O(1) operations,O(n) worst transfer,O(n)
storage. PITFALL: Transferring while outgoing is nonempty breaks FIFO order. PRACTICE: Change
the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

class TwoStackQueue {
    std::vector<int> incoming;
    std::vector<int> outgoing;

    void prepare() {
        if (outgoing.empty()) {
            while (!incoming.empty()) {
                outgoing.push_back(incoming.back());
                incoming.pop_back();
            }
        }
    }

public:
    void push(int value) {
        incoming.push_back(value);
    }

    std::optional<int> front() {
        prepare();
        if (outgoing.empty()) {
            return std::nullopt;
        }
        return outgoing.back();
    }

    std::optional<int> pop() {
        prepare();
        if (outgoing.empty()) {
            return std::nullopt;
        }
        int value = outgoing.back();
        outgoing.pop_back();
        return value;
    }
};

int main() {
    TwoStackQueue queue;
    assert(!queue.pop());
    queue.push(1);
    queue.push(2);
    assert(queue.pop() == 1);
    queue.push(3);
    assert(queue.front() == 2);
    assert(queue.pop() == 2);
    assert(queue.pop() == 3);
    assert(!queue.front());
    std::cout << "checks passed\n";
    return 0;
}
