/*
 Return unique sorted triples summing to 0; input is copied and may contain duplicates.

IDEA AND STATE: Sort, skip equal anchors, and skip equal pair endpoints after emitting a match.

TRACE: -1,0,1,2,-1,-4 ->[-1,-1,2],[-1,0,1].

After sorting,anchor -1 finds -1+2 and0+1;the repeated -1 anchor is skipped.

For each anchor, sorted two-sum explores all feasible pairs; duplicate skips remove
repeated value triples without losing distinct ones.

O(n^2) time, O(n) copied/sorting storage plus output.

Use a wide sum and distinguish unique value triples from distinct index triples.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    std::vector<std::vector<int>> result;
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i] == a[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            long long sum = 1LL * a[i] + a[left] + a[right];
            if (sum == 0) {
                result.push_back({a[i], a[left], a[right]});
                int x = a[left];
                int y = a[right];
                while (left < right && a[left] == x) {
                    ++left;
                }
                while (left < right && a[right] == y) {
                    --right;
                }
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return result;
}

int main() {
    assert((threeSum({-1, 0, 1, 2, -1, -4})
            == std::vector<std::vector<int>>{{-1, -1, 2}, {-1, 0, 1}}));
    assert((threeSum({0, 0, 0, 0}) == std::vector<std::vector<int>>{{0, 0, 0}}));
    assert(threeSum({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
