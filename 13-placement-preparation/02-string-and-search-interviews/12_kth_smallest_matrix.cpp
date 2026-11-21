/*
 Nonempty rectangular matrix, rows and columns sorted; valid 1-based rank. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

count(mid) is the number of entries<=mid; seek the first value with
count>=k.

The eighth sorted entry is 13, including both copies.

Counting is monotone in mid, and the first threshold reaching k equals the kth
multiset value.

O(rows*log(cols+1)*log(value range+1)) time, O(1) work.

The answer search is over values, not flattened row-major positions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int rankValue(const std::vector<std::vector<int>>& a, int k) {
    int low = a[0][0];
    int high = a.back().back();
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (const auto& row : a) {
            count += static_cast<int>(std::upper_bound(row.begin(), row.end(), mid) - row.begin());
        }
        if (count >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    assert(rankValue({{1, 5, 9}, {10, 11, 13}, {12, 13, 15}}, 8) == 13);
    assert(rankValue({{-5}}, 1) == -5);
    std::cout << "checks passed\n";
    return 0;
}
