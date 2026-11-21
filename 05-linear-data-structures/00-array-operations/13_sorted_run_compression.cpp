/*
COMPRESS SORTED RUNS WITH COUNTS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Nondecreasing int vector. IDEA AND STATE: Scan each maximal equal run and
emit(value,count). TRACE: 1,1,2,4,4,4 ->(1,2),(2,1),(4,3). CORRECTNESS: Runs partition the
input and each output records exactly its run length. COST: O(n) time,O(u) output space for u
distinct values. PITFALL: An unsorted input counts adjacent runs instead of global frequency.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> runs(const std::vector<int>& a) {
    std::vector<std::pair<int, int>> out;
    std::size_t i = 0;
    while (i < a.size()) {
        std::size_t end = i + 1;
        while (end < a.size() && a[end] == a[i]) {
            ++end;
        }
        out.push_back({a[i], static_cast<int>(end - i)});
        i = end;
    }
    return out;
}

int main() {
    assert((runs({1, 1, 2, 4, 4, 4}) == std::vector<std::pair<int, int>>{{1, 2}, {2, 1}, {4, 3}}));
    assert(runs({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
