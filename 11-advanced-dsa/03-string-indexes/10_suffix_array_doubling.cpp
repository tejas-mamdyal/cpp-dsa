/*
 Byte string, length<=1000; sort suffix starting indices lexicographically. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

rank[i] orders the current fixed-length suffix prefix; sort pairs of its
first and second half ranks, then assign new equivalence ranks.

banana suffix order is a, ana, anana, banana, na, nana, starting at 5,3,1,0,4,2.

Pair lexicographic order compares exactly the doubled prefix; once ranks are
unique or width covers the string, the full suffix order is known.

O(n log^2(n+1)) time with comparison sorting, O(n) auxiliary.

Missing second halves use rank-1, smaller than every byte rank; no special input
separator is required.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>

std::vector<int> suffixArray(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> order(s.size());
    std::iota(order.begin(), order.end(), 0);
    std::vector<int> rank;
    for (unsigned char ch : s) {
        rank.push_back(ch);
    }
    for (int width = 1; width < n; width *= 2) {
        std::sort(order.begin(), order.end(), [&](int a, int b) {
            auto first = std::pair<int, int>{rank[a], a + width < n ? rank[a + width] : -1};
            auto second = std::pair<int, int>{rank[b], b + width < n ? rank[b + width] : -1};
            return first < second;
        });
        std::vector<int> next(s.size(), 0);
        for (int i = 1; i < n; ++i) {
            int a = order[i - 1];
            int b = order[i];
            auto first = std::pair<int, int>{rank[a], a + width < n ? rank[a + width] : -1};
            auto second = std::pair<int, int>{rank[b], b + width < n ? rank[b + width] : -1};
            next[b] = next[a] + (first != second);
        }
        rank = std::move(next);
        if (rank[order.back()] == n - 1) {
            break;
        }
    }
    return order;
}

int main() {
    assert((suffixArray("banana") == std::vector<int>{5, 3, 1, 0, 4, 2}));
    assert(suffixArray("").empty());
    assert(suffixArray("x") == std::vector<int>{0});
    std::cout << "checks passed\n";
    return 0;
}
