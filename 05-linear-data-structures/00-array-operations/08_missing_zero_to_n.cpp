/*
FIND ONE MISSING VALUE BY XOR PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 n distinct values selected from0..n; exactly one missing. IDEA AND STATE: XOR all
indices0..n and all supplied values. TRACE: 3,0,1 ->missing2. CORRECTNESS: Every present
number cancels its counterpart, leaving the absent one. COST: O(n) time,O(1) space. PITFALL:
Distinctness/range are preconditions; XOR is not their validator. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int missing(const std::vector<int>& a) {
    int result = static_cast<int>(a.size());
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        result ^= i;
        result ^= a[i];
    }
    return result;
}

int main() {
    assert(missing({3, 0, 1}) == 2);
    assert(missing({}) == 0);
    assert(missing({0}) == 1);
    assert(missing({1}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
