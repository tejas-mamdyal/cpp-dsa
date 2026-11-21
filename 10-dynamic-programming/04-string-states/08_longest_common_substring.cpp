/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

dp[i][j] is length of the common contiguous suffix ending at both selected
positions; global best may occur anywhere.

abc versus ac has LCS 2 but longest common substring 1 because b prevents
contiguity.

Equal ending characters extend only the immediately preceding matching diagonal;
unequal ends cannot have a positive common suffix.

O(n*m) time, O(m) auxiliary.

Do not use neighboring maximum skips; those compute subsequences.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cstddef>

int substring(const std::string& a, const std::string& b) {
    std::vector<int> previous(b.size() + 1, 0);
    int best = 0;
    for (char x : a) {
        std::vector<int> current(b.size() + 1, 0);
        for (std::size_t j = 1; j <= b.size(); ++j) {
            if (x == b[j - 1]) {
                current[j] = 1 + previous[j - 1];
                best = std::max(best, current[j]);
            }
        }
        previous = std::move(current);
    }
    return best;
}

int main() {
    assert(substring("abcdxyz", "xyzabcd") == 4);
    assert(substring("abc", "ac") == 1);
    assert(substring("", "abc") == 0);
    std::cout << "checks passed\n";
    return 0;
}
