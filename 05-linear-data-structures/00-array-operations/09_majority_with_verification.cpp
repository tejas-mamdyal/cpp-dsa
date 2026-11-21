/*
MAJORITY CANDIDATE MUST BE VERIFIED PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Return a value occurring more than n/2 times or absence. IDEA AND STATE: Cancel
unlike pairs to choose a candidate; scan again to verify. TRACE: 2,2,1,2 ->2;1,2,3 ->absence.
CORRECTNESS: A true majority survives pair cancellation; verification rejects false
candidates. COST: O(n) time,O(1) space. PITFALL: The candidate alone is not evidence that a
majority exists. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

std::optional<int> majority(const std::vector<int>& a) {
    int candidate = 0;
    int balance = 0;
    for (int value : a) {
        if (balance == 0) {
            candidate = value;
        }
        if (value == candidate) {
            ++balance;
        } else {
            --balance;
        }
    }
    std::size_t count = 0;
    for (int value : a) {
        if (value == candidate) {
            ++count;
        }
    }
    if (count > a.size() / 2) {
        return candidate;
    }
    return std::nullopt;
}

int main() {
    assert(majority({2, 2, 1, 2}) == 2);
    assert(!majority({1, 2, 3}));
    assert(!majority({}));
    assert(!majority({1, 2}));
    std::cout << "checks passed\n";
    return 0;
}
