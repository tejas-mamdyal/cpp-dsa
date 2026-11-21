/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

previous[j] stores old dp[i-1][j]; current[j-1] already stores new
dp[i][j-1].

The first row represents inserting target prefixes; each source character creates
a new row beginning with its deletion count.

All three dependencies of the full table remain available in the two-row
representation.

O(n*m) time, O(m) auxiliary.

In-place overwrite needs an additional saved diagonal; two explicit rows are clearer
initially.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cstddef>
#include <numeric>

int edits(const std::string& a, const std::string& b) {
    std::vector<int> previous(b.size() + 1);
    std::iota(previous.begin(), previous.end(), 0);
    for (std::size_t i = 1; i <= a.size(); ++i) {
        std::vector<int> current(b.size() + 1);
        current[0] = static_cast<int>(i);
        for (std::size_t j = 1; j <= b.size(); ++j) {
            current[j] = a[i - 1] == b[j - 1]
                             ? previous[j - 1]
                             : 1 + std::min({previous[j], current[j - 1], previous[j - 1]});
        }
        previous = std::move(current);
    }
    return previous.back();
}

int main() {
    assert(edits("kitten", "sitting") == 3);
    assert(edits("abc", "") == 3);
    assert(edits("", "") == 0);
    std::cout << "checks passed\n";
    return 0;
}
