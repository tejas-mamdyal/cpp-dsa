/*
 At most 30 values; return unique sorted quadruples with the requested sum.

IDEA AND STATE: Sort, choose two anchors, then solve the remaining pair with duplicate skips.

TRACE: 1,0,-1,0,-2,2 target 0 has 3 unique quadruples.

Sort to -2,-1,0,0,1,2;anchors -2,-1 find1,2,and duplicate skipping retains only three distinct
results.

Every quadruple has a first two sorted positions; two-sum finds its remaining pair
once per value combination.

O(n^3) time, O(n) copy plus output.

Do not add four ints before widening; different multiplicities require enough
positions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int> a, long long target) {
    std::sort(a.begin(), a.end());
    std::vector<std::vector<int>> out;
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i] == a[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < n; ++j) {
            if (j > i + 1 && a[j] == a[j - 1]) {
                continue;
            }
            int l = j + 1;
            int r = n - 1;
            while (l < r) {
                long long sum = 1LL * a[i] + a[j] + a[l] + a[r];
                if (sum == target) {
                    out.push_back({a[i], a[j], a[l], a[r]});
                    int x = a[l];
                    int y = a[r];
                    while (l < r && a[l] == x) {
                        ++l;
                    }
                    while (l < r && a[r] == y) {
                        --r;
                    }
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
    }
    return out;
}

int main() {
    assert((fourSum({1, 0, -1, 0, -2, 2}, 0)
            == std::vector<std::vector<int>>{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}));
    assert(fourSum({1, 2, 3}, 0).empty());
    assert((fourSum({2, 2, 2, 2, 2}, 8) == std::vector<std::vector<int>>{{2, 2, 2, 2}}));
    std::cout << "checks passed\n";
    return 0;
}
