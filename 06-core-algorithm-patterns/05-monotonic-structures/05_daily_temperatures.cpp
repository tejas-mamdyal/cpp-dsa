/*
 Return days until strictly warmer, or 0.

IDEA AND STATE: Resolve cooler days with the current day; distance is current minus stored
index.

TRACE: 73,74,75,71,69,72,76,73 ->1,1,4,2,1,1,0,0.

Day1 resolves day0 in1 day;day6 resolves the remaining cooler days including day2 at
distance4.

The first future warmer day to pop a waiting day is its closest answer.

O(n) time, O(n) space.

Equal temperatures do not resolve a day.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> waits(const std::vector<int>& a) {
    std::vector<int> out(a.size(), 0);
    std::vector<int> stack;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        while (!stack.empty() && a[stack.back()] < a[i]) {
            out[stack.back()] = i - stack.back();
            stack.pop_back();
        }
        stack.push_back(i);
    }
    return out;
}

int main() {
    assert((waits({73, 74, 75, 71, 69, 72, 76, 73}) == std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
    assert((waits({5, 5}) == std::vector<int>{0, 0}));
    std::cout << "checks passed\n";
    return 0;
}
