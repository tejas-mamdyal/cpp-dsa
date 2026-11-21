/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

A suffix of length n-start contributes all its prefixes except the lcp
with its previous lexicographic neighbor.

Repeated prefixes of aaa subtract to leave only a, aa, aaa.

Previously seen suffix-prefix duplicates are exactly prefixes no longer than the
maximum earlier suffix overlap, attained by the lexicographic predecessor.

O(n log^2 n) with the preceding suffix builder, O(n) extra arrays.

Do not count the empty substring unless explicitly requested.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cstddef>
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

long long distinct(const std::string& s) {
    auto order = suffixArray(s);
    auto lcp = lcpArray(s, order);
    long long total = 0;
    for (std::size_t i = 0; i < order.size(); ++i) {
        total += static_cast<long long>(s.size()) - order[i] - lcp[i];
    }
    return total;
}

int main() {
    assert(distinct("ababa") == 9);
    assert(distinct("aaa") == 3);
    assert(distinct("") == 0);
    std::cout << "checks passed\n";
    return 0;
}
