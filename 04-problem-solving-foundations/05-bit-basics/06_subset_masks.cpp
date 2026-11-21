/*
ENUMERATE BOUNDED SUBSETS BY MASKS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 At most10 distinct input ints; retain all subset outputs. IDEA AND STATE: Bit i
indicates membership of input position i. TRACE: 1,2 produces[],[1],[2],[1,2]. CORRECTNESS:
Every subset has exactly one membership mask and each mask is visited once. COST: O(n*2^n)
time and output storage,O(n) temporary subset. PITFALL: Validate n before shifting; an empty
input still has the empty subset. PRACTICE: Change the example, predict each state update and
add an empty/boundary case. No input unless explicitly stated. Assertions are the teaching
test harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>

std::vector<std::vector<int>> subsets(const std::vector<int>& a) {
    assert(a.size() <= 10);
    unsigned int total = 1U << a.size();
    std::vector<std::vector<int>> result;
    for (unsigned int mask = 0; mask < total; ++mask) {
        std::vector<int> current;
        for (std::size_t i = 0; i < a.size(); ++i) {
            if ((mask & (1U << i)) != 0U) {
                current.push_back(a[i]);
            }
        }
        result.push_back(current);
    }
    return result;
}

int main() {
    assert((subsets({1, 2}) == std::vector<std::vector<int>>{{}, {1}, {2}, {1, 2}}));
    assert((subsets({}) == std::vector<std::vector<int>>{{}}));
    std::cout << "checks passed\n";
    return 0;
}
