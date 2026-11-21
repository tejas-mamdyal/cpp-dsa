/*
 Fixed positive k; invalid sizes return empty vector.

IDEA AND STATE: Expire indices at the front, pop no-larger values at the back.

TRACE: 1,3,-1,-3,5,3,6,7 with k 3 ->3,3,5,5,6,7.

At width3,the deque front is value3;the arriving5 discards smaller candidates and becomes the
next maximum.

Older no-larger values can never beat the new value before they expire; the front
is the live maximum.

O(n) time, O(k) auxiliary space excluding output.

Store indices so expiry can be checked.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

std::vector<int> windowMax(const std::vector<int>& a, int k) {
    if (k < 1 || k > static_cast<int>(a.size())) {
        return {};
    }
    std::deque<int> q;
    std::vector<int> out;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        while (!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] <= a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k - 1) {
            out.push_back(a[q.front()]);
        }
    }
    return out;
}

int main() {
    assert((windowMax({1, 3, -1, -3, 5, 3, 6, 7}, 3) == std::vector<int>{3, 3, 5, 5, 6, 7}));
    assert(windowMax({}, 1).empty());
    assert((windowMax({2, 2}, 1) == std::vector<int>{2, 2}));
    std::cout << "checks passed\n";
    return 0;
}
