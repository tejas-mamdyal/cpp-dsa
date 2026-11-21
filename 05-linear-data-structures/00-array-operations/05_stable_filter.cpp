/*
STABLE COMPACTION WITH A WRITE PREFIX PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Remove all selected values in place. IDEA AND STATE: Write only retained values into
an earlier prefix, then resize. TRACE: 1,0,2,0 ->remove0 ->1,2. CORRECTNESS: The write index
never outruns reading, so unread values survive and retained order is unchanged. COST: O(n)
time,O(1) auxiliary space. PITFALL: Shrinking inside the loop can invalidate traversal.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void removeValue(std::vector<int>& a, int target) {
    std::size_t write = 0;
    for (int value : a) {
        if (value != target) {
            a[write++] = value;
        }
    }
    a.resize(write);
}

int main() {
    std::vector<int> a = {1, 0, 2, 0};
    removeValue(a, 0);
    assert((a == std::vector<int>{1, 2}));
    removeValue(a, 1);
    assert((a == std::vector<int>{2}));
    removeValue(a, 2);
    assert(a.empty());
    removeValue(a, 2);
    std::cout << "checks passed\n";
    return 0;
}
