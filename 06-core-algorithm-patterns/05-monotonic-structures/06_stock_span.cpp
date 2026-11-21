/*
 Return consecutive previous days including today whose prices are <= today.

IDEA AND STATE: Pop <= prices, then measure distance from previous greater.

TRACE: 100,80,60,70,60,75,85 ->1,1,1,2,1,4,6.

Price75 pops60 and70 and60 before meeting80;its span is4;85 then spans6.

Every popped day belongs inside the new span; the remaining top blocks further
extension.

O(n) time, O(n) space.

Equal prices belong in the span.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> spans(const std::vector<int>& a) {
    std::vector<int> out;
    std::vector<int> stack;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        while (!stack.empty() && a[stack.back()] <= a[i]) {
            stack.pop_back();
        }
        int boundary = stack.empty() ? -1 : stack.back();
        out.push_back(i - boundary);
        stack.push_back(i);
    }
    return out;
}

int main() {
    assert((spans({100, 80, 60, 70, 60, 75, 85}) == std::vector<int>{1, 1, 1, 2, 1, 4, 6}));
    assert((spans({5, 5}) == std::vector<int>{1, 2}));
    std::cout << "checks passed\n";
    return 0;
}
