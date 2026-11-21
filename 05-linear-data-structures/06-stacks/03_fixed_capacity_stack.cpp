/*
FULL AND EMPTY ARE SEPARATE STATES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Capacity3; push false on full, pop/peek optional on empty. IDEA AND STATE: A count
identifies the first unused array slot. TRACE: push1,2,3 fills;push4 fails;pop yields3.
CORRECTNESS: Indices[0,count) are live values and count stays within0..capacity. COST: O(1)
operations,O(capacity) storage. PITFALL: A failed push must leave the old top unchanged.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <array>
#include <optional>

class FixedStack {
    std::array<int, 3> data{};
    std::size_t used = 0;

public:
    bool push(int value) {
        if (used == data.size()) {
            return false;
        }
        data[used++] = value;
        return true;
    }

    std::optional<int> pop() {
        if (used == 0) {
            return std::nullopt;
        }
        --used;
        return data[used];
    }

    std::optional<int> peek() const {
        if (used == 0) {
            return std::nullopt;
        }
        return data[used - 1];
    }
};

int main() {
    FixedStack stack;
    assert(!stack.pop());
    assert(stack.push(1) && stack.push(2) && stack.push(3));
    assert(!stack.push(4));
    assert(stack.peek() == 3);
    assert(stack.pop() == 3);
    assert(stack.pop() == 2);
    assert(stack.pop() == 1);
    assert(!stack.peek());
    std::cout << "checks passed\n";
    return 0;
}
