/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[i] is best ending length; parent[i] records an earlier smaller
predecessor only on strict length improvement.

For 3,1,2,4, parents connect 4 to 2 to 1, then reverse output 1,2,4.

Parent indices decrease and values strictly increase forward, while each edge
increases the stored subsequence length by 1.

O(n^2) time, O(n) states/witness.

Returning indices may be preferable when duplicate values must identify exact
positions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> sequence(const std::vector<int>& a) {
    if (a.empty()) {
        return {};
    }
    std::vector<int> dp(a.size(), 1);
    std::vector<int> parent(a.size(), -1);
    int best = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > dp[best]) {
            best = i;
        }
    }
    std::vector<int> out;
    for (int i = best; i != -1; i = parent[i]) {
        out.push_back(a[i]);
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    auto out = sequence({3, 1, 2, 4});
    assert((out == std::vector<int>{1, 2, 4}));
    assert(sequence({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
