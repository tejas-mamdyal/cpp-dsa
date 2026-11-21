/*
 Both inputs sorted; return distinct shared values in increasing order.

IDEA AND STATE: Advance the smaller head; on equality emit unless already emitted and advance
both.

TRACE: 1,1,2 with 1,2,2 ->1,2.

Match1 once,skip duplicate1 on the left,then match2 once and suppress its repeated copy.

A smaller current head cannot match any remaining value of the other sequence.

O(n+m) time, O(k) output, O(1) working state.

Distinct intersection differs from multiset multiplicity intersection.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> intersection(const std::vector<int>& a, const std::vector<int>& b) {
    std::size_t i = 0;
    std::size_t j = 0;
    std::vector<int> out;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ++i;
        } else if (b[j] < a[i]) {
            ++j;
        } else {
            if (out.empty() || out.back() != a[i]) {
                out.push_back(a[i]);
            }
            ++i;
            ++j;
        }
    }
    return out;
}

int main() {
    assert((intersection({1, 1, 2}, {1, 2, 2}) == std::vector<int>{1, 2}));
    assert(intersection({}, {1}).empty());
    assert(intersection({1}, {2}).empty());
    std::cout << "checks passed\n";
    return 0;
}
