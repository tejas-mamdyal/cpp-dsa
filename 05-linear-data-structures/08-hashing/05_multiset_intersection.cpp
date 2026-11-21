/*
CONSUME FREQUENCY COUNTS FOR MULTIPLICITY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Output common occurrences in the second input encounter order. IDEA AND STATE: Store
counts from the first input and decrement only when consuming a match. TRACE: 1,1,2
with1,2,1,1 ->1,2,1. CORRECTNESS: A count permits at most the available number of each value
to be emitted. COST: Expected O(n+m) time,O(u+k) storage including k output; worst hashing
degrades. PITFALL: A membership set would lose multiplicities. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

std::vector<int> common(const std::vector<int>& a, const std::vector<int>& b) {
    std::unordered_map<int, int> count;
    for (int value : a) {
        ++count[value];
    }
    std::vector<int> result;
    for (int value : b) {
        auto it = count.find(value);
        if (it != count.end() && it->second > 0) {
            result.push_back(value);
            --it->second;
        }
    }
    return result;
}

int main() {
    assert((common({1, 1, 2}, {1, 2, 1, 1}) == std::vector<int>{1, 2, 1}));
    assert(common({}, {1}).empty());
    assert(common({1}, {2}).empty());
    std::cout << "checks passed\n";
    return 0;
}
