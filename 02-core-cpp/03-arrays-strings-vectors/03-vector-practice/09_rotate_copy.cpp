/*
ROTATE A VECTOR LEFT BY K
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Normalize k modulo n and copy element (i+k)%n into output position i; empty input returns immediately.
Trace: 1,2,3,4 rotated left by6 ->3,4,1,2.
Why it works: Modulo maps every result position to exactly one source position.
Cost: O(n) time and O(n) result space.
Common mistake: Never compute k%n when n is zero; this helper accepts nonnegative k.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> rotateLeft(const std::vector<int>& values, std::size_t k) {
    if (values.empty()) {
        return {};
    }
    k %= values.size();
    std::vector<int> result(values.size());
    for (std::size_t i = 0; i < values.size(); ++i) {
        result[i] = values[(i + k) % values.size()];
    }
    return result;
}

int main() {
    assert((rotateLeft({1, 2, 3, 4}, 6) == std::vector<int>{3, 4, 1, 2}));
    assert(rotateLeft({}, 7).empty());
    assert((rotateLeft({9}, 0) == std::vector<int>{9}));
    std::cout << "checks passed\n";
}
