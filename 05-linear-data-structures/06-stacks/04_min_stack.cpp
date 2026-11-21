/*
STORE THE MINIMUM OF EVERY LIVE PREFIX PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 An unbounded value stack; return absence when empty. IDEA AND STATE: Each entry
stores value and minimum up to that entry. TRACE: push3,1,1,pop still has minimum1.
CORRECTNESS: The previous entry already contains the correct minimum when the top is removed.
COST: Amortized O(1) push,O(1) pop/min,O(n) storage. PITFALL: Equal minima need independent
entries so one pop does not discard both. PRACTICE: Change the example, predict each state
update and add an empty/boundary case. No input unless explicitly stated. Assertions are the
teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>

class MinStack {
    std::vector<std::pair<int, int>> data;

public:
    void push(int value) {
        int minimum = value;
        if (!data.empty()) {
            minimum = std::min(minimum, data.back().second);
        }
        data.push_back({value, minimum});
    }

    std::optional<int> pop() {
        if (data.empty()) {
            return std::nullopt;
        }
        int value = data.back().first;
        data.pop_back();
        return value;
    }

    std::optional<int> minimum() const {
        if (data.empty()) {
            return std::nullopt;
        }
        return data.back().second;
    }
};

int main() {
    MinStack stack;
    assert(!stack.minimum());
    stack.push(3);
    stack.push(1);
    stack.push(1);
    assert(stack.minimum() == 1);
    assert(stack.pop() == 1);
    assert(stack.minimum() == 1);
    assert(stack.pop() == 1);
    assert(stack.minimum() == 3);
    assert(stack.pop() == 3);
    assert(!stack.pop());
    std::cout << "checks passed\n";
    return 0;
}
