/*
 Nonnegative unit-width heights; empty water 0.

IDEA AND STATE: Pop a basin bottom when a right wall rises; remaining top is the left wall.

TRACE: 3,0,2,0,4 ->7.

At right wall2,pop the first0 and add2;at wall4,remaining basin layers contribute5
more,total7.

Each pop fills a disjoint layer between two walls; layers partition trapped water.

O(n) time, O(n) space.

Without a remaining left wall no basin is enclosed.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long water(const std::vector<int>& h) {
    std::vector<int> stack;
    long long out = 0;
    for (int i = 0; i < static_cast<int>(h.size()); ++i) {
        while (!stack.empty() && h[i] > h[stack.back()]) {
            int bottom = stack.back();
            stack.pop_back();
            if (stack.empty()) {
                break;
            }
            int left = stack.back();
            out += 1LL * (std::min(h[left], h[i]) - h[bottom]) * (i - left - 1);
        }
        stack.push_back(i);
    }
    return out;
}

long long slowWater(const std::vector<int>& h) {
    long long out = 0;
    for (std::size_t i = 0; i < h.size(); ++i) {
        int left = 0;
        int right = 0;
        for (std::size_t j = 0; j <= i; ++j) {
            left = std::max(left, h[j]);
        }
        for (std::size_t j = i; j < h.size(); ++j) {
            right = std::max(right, h[j]);
        }
        out += std::min(left, right) - h[i];
    }
    return out;
}

int main() {
    assert(water({3, 0, 2, 0, 4}) == 7);
    for (int n = 0; n <= 6; ++n) {
        int cases = 1;
        for (int i = 0; i < n; ++i) {
            cases *= 3;
        }
        for (int code = 0; code < cases; ++code) {
            int value = code;
            std::vector<int> h(static_cast<std::size_t>(n));
            for (int& x : h) {
                x = value % 3;
                value /= 3;
            }
            assert(water(h) == slowWater(h));
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
