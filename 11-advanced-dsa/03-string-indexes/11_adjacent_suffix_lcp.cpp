/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

lcp[rank] is common-prefix length with the previous suffix in suffix
order; lcp 0=0. Reuse common-1 after advancing the original start index.

ana and anana share ana length 3; na and nana share na length 2.

Removing the first character from a shared prefix leaves a shared prefix one
shorter; rank-neighbor structure bounds required new comparisons.

O(n) LCP construction after suffix array, O(n) arrays.

The supplied order must be a valid suffix permutation; this helper does not validate
arbitrary external ranks.
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

std::vector<int> lcpArray(const std::string& s, const std::vector<int>& order) {
    int n = static_cast<int>(s.size());
    std::vector<int> rank(s.size());
    for (int i = 0; i < n; ++i) {
        rank[order[i]] = i;
    }
    std::vector<int> lcp(s.size(), 0);
    int common = 0;
    for (int i = 0; i < n; ++i) {
        int place = rank[i];
        if (place == 0) {
            common = 0;
            continue;
        }
        int j = order[place - 1];
        while (i + common < n && j + common < n && s[i + common] == s[j + common]) {
            ++common;
        }
        lcp[place] = common;
        if (common > 0) {
            --common;
        }
    }
    return lcp;
}

int main() {
    assert((lcpArray("banana", suffixArray("banana")) == std::vector<int>{0, 1, 3, 0, 0, 2}));
    assert(lcpArray("", {}).empty());
    std::cout << "checks passed\n";
    return 0;
}
