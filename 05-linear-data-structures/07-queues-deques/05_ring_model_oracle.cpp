/*
COMPARE WRAPAROUND BEHAVIOR WITH AN INDEPENDENT DEQUE PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Fixed capacity4; deterministic mixed operations. IDEA AND STATE: After every
push/pop compare return status,front and size against std::deque. TRACE: Repeated
filling,overflow rejection,popping and wrapping preserve FIFO state. CORRECTNESS: The model
independently records logical order rather than reproducing ring arithmetic. COST: O(1)
operations,O(capacity) storage;200 bounded test operations. PITFALL: Checking only one wrap
does not cover repeated full/empty transitions. PRACTICE: Change the example, predict each
state update and add an empty/boundary case. No input unless explicitly stated. Assertions are
the teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <array>
#include <deque>
#include <optional>

class Ring {
    std::array<int, 4> data{};
    std::size_t first = 0;
    std::size_t count = 0;

public:
    bool push(int value) {
        if (count == data.size()) {
            return false;
        }
        data[(first + count) % data.size()] = value;
        ++count;
        return true;
    }

    std::optional<int> pop() {
        if (count == 0) {
            return std::nullopt;
        }
        int value = data[first];
        first = (first + 1) % data.size();
        --count;
        return value;
    }

    std::optional<int> front() const {
        if (count == 0) {
            return std::nullopt;
        }
        return data[first];
    }

    std::size_t size() const {
        return count;
    }
};

int main() {
    Ring ring;
    std::deque<int> model;
    for (int step = 0; step < 200; ++step) {
        if (step % 5 < 3) {
            bool expected = model.size() < 4;
            assert(ring.push(step) == expected);
            if (expected) {
                model.push_back(step);
            }
        } else {
            auto value = ring.pop();
            if (model.empty()) {
                assert(!value);
            } else {
                assert(value == model.front());
                model.pop_front();
            }
        }
        assert(ring.size() == model.size());
        if (model.empty()) {
            assert(!ring.front());
        } else {
            assert(ring.front() == model.front());
        }
    }
    while (!model.empty()) {
        assert(ring.pop() == model.front());
        model.pop_front();
    }
    assert(!ring.pop());
    std::cout << "checks passed\n";
    return 0;
}
