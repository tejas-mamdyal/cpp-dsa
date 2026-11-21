/*
 Positive stick length<=1000; distinct required cuts strictly inside it,<=20. Unless
a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

best[l][r] minimizes all required interior cuts in the original endpoint
interval.

Cut 3 first costs 7, then solve its two shorter sticks.

The first cut splits the remaining work into independent intervals; try every
possible first cut.

O(c^3) time, O(c^2) storage.

The cost is the current segment length, not the distance from its left end to the
chosen cut.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int cutCost(int length, std::vector<int> cuts) {
    cuts.push_back(0);
    cuts.push_back(length);
    std::sort(cuts.begin(), cuts.end());
    int n = static_cast<int>(cuts.size());
    std::vector<std::vector<int>> best(n, std::vector<int>(n));
    for (int gap = 2; gap < n; ++gap) {
        for (int left = 0; left + gap < n; ++left) {
            int right = left + gap;
            best[left][right] = 1000000000;
            for (int mid = left + 1; mid < right; ++mid) {
                best[left][right] =
                    std::min(best[left][right],
                             cuts[right] - cuts[left] + best[left][mid] + best[mid][right]);
            }
        }
    }
    return best[0][n - 1];
}

int main() {
    assert(cutCost(7, {1, 3, 4, 5}) == 16);
    assert(cutCost(9, {}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
