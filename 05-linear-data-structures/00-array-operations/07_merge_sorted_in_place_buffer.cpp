/*
MERGE INTO RESERVED TRAILING SLOTS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 a has m valid sorted values and n extra live slots; b has n sorted values. IDEA AND
STATE: Fill from the back so unread a values are not overwritten. TRACE: a1,3,5,_,_,_ and
b2,4,6 ->1,2,3,4,5,6. CORRECTNESS: The greatest remaining value belongs at the last unused
output position. COST: O(m+n) time,O(1) extra space beyond provided slots. PITFALL: Allocated
capacity alone is not live indexed storage; a must have size m+n. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void mergeInto(std::vector<int>& a, int m, const std::vector<int>& b) {
    assert(a.size() == static_cast<std::size_t>(m) + b.size());
    int i = m - 1;
    int j = static_cast<int>(b.size()) - 1;
    int write = static_cast<int>(a.size()) - 1;
    while (j >= 0) {
        if (i >= 0 && a[i] > b[j]) {
            a[write--] = a[i--];
        } else {
            a[write--] = b[j--];
        }
    }
}

int main() {
    std::vector<int> a = {1, 3, 5, 0, 0, 0};
    mergeInto(a, 3, {2, 4, 6});
    assert((a == std::vector<int>{1, 2, 3, 4, 5, 6}));
    std::vector<int> b(2);
    mergeInto(b, 0, {1, 2});
    assert((b == std::vector<int>{1, 2}));
    std::vector<int> empty;
    mergeInto(empty, 0, {});
    std::cout << "checks passed\n";
    return 0;
}
