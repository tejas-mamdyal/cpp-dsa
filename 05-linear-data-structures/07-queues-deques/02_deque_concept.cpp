/*
A RING DEQUE IMPLEMENTS BOTH ENDPOINTS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Positive fixed capacity; failed pushes and empty pops leave state unchanged. IDEA
AND STATE: Logical front/count map both endpoints into circular indices. TRACE:
pushBack2,pushFront1,pushBack3 ->popBack3,popFront1,popFront2. CORRECTNESS: The used logical
interval retains its order even when physical indices wrap. COST: O(1) operations,O(capacity)
storage. PITFALL: Use front+capacity-1 instead of unsigned front-1 before modulo. PRACTICE:
Change the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <stdexcept>

class RingDeque {
    std::vector<int> data;
    std::size_t front = 0;
    std::size_t used = 0;

public:
    explicit RingDeque(int capacity) {
        if (capacity < 1 || capacity > 1000) {
            throw std::invalid_argument("capacity");
        }
        data.resize(static_cast<std::size_t>(capacity));
    }

    bool pushBack(int value) {
        if (used == data.size()) {
            return false;
        }
        data[(front + used) % data.size()] = value;
        ++used;
        return true;
    }

    bool pushFront(int value) {
        if (used == data.size()) {
            return false;
        }
        front = (front + data.size() - 1) % data.size();
        data[front] = value;
        ++used;
        return true;
    }

    std::optional<int> popFront() {
        if (used == 0) {
            return std::nullopt;
        }
        int value = data[front];
        front = (front + 1) % data.size();
        --used;
        return value;
    }

    std::optional<int> popBack() {
        if (used == 0) {
            return std::nullopt;
        }
        std::size_t index = (front + used - 1) % data.size();
        int value = data[index];
        --used;
        return value;
    }
};

int main() {
    RingDeque deque(3);
    assert(!deque.popFront());
    assert(deque.pushBack(2));
    assert(deque.pushFront(1));
    assert(deque.pushBack(3));
    assert(!deque.pushFront(0));
    assert(deque.popBack() == 3);
    assert(deque.popFront() == 1);
    assert(deque.popFront() == 2);
    assert(!deque.popBack());
    assert(deque.pushFront(7));
    assert(deque.popBack() == 7);
    std::cout << "checks passed\n";
    return 0;
}
