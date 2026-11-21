/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

length[i] is the best ending length; ways[i] counts positional
subsequences attaining exactly that length.

1,3,5,4,7 has two optimum endings via 5 or 4, so length 4, count 2.

Strict improvements replace inferior counts; equal optimum predecessors
contribute disjoint final-index histories.

O(n^2) time, O(n) states; counts bounded by 2^30.

Always adding counts would mix shorter nonoptimal subsequences into the answer.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstddef>

std::pair<int, long long> countLIS(const std::vector<int>& a) {
    if (a.empty()) {
        return {0, 0};
    }
    std::vector<int> length(a.size(), 1);
    std::vector<long long> ways(a.size(), 1);
    for (std::size_t i = 0; i < a.size(); ++i) {
        for (std::size_t j = 0; j < i; ++j) {
            if (a[j] >= a[i]) {
                continue;
            }
            if (length[j] + 1 > length[i]) {
                length[i] = length[j] + 1;
                ways[i] = ways[j];
            } else if (length[j] + 1 == length[i]) {
                ways[i] += ways[j];
            }
        }
    }
    int best = *std::max_element(length.begin(), length.end());
    long long count = 0;
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (length[i] == best) {
            count += ways[i];
        }
    }
    return {best, count};
}

int main() {
    assert((countLIS({1, 3, 5, 4, 7}) == std::pair<int, long long>{4, 2}));
    assert((countLIS({2, 2, 2}) == std::pair<int, long long>{1, 3}));
    assert(countLIS({}).second == 0);
    std::cout << "checks passed\n";
    return 0;
}
