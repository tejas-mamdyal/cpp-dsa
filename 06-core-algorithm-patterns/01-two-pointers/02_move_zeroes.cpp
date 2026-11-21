/*
 Move zeros to the end without reordering nonzero elements.

IDEA AND STATE: Read every value; write retained values to an earlier prefix, then fill the rest
with zero.

TRACE: 0,3,0,1 ->3,1,0,0.

Read0 without writing,copy3 to slot0,skip0,copy1 to slot1,then fill slots2 and3 with zeros.

write never outruns read, so unread elements survive and retained encounter order
is preserved.

O(n) time, O(1) extra space.

Repeated erase is quadratic; swapping with the tail loses stable order.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int>& a) {
    std::size_t write = 0;
    for (int value : a) {
        if (value != 0) {
            a[write] = value;
            ++write;
        }
    }
    while (write < a.size()) {
        a[write] = 0;
        ++write;
    }
}

int main() {
    for (std::vector<int> a :
         std::vector<std::vector<int>>{{}, {0}, {1}, {0, 3, 0, 1}, {0, 0}, {-2, 0, 5}}) {
        std::vector<int> expected;
        for (int value : a) {
            if (value != 0) {
                expected.push_back(value);
            }
        }
        expected.resize(a.size(), 0);
        moveZeroes(a);
        assert(a == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
