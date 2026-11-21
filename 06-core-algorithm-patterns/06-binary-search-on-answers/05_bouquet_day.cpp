/*
 Nonnegative bloom days; m>=0 bouquets, k>0 consecutive flowers per bouquet, no reuse.

IDEA AND STATE: At a candidate day, accumulate available runs and reset after every completed
bouquet.

TRACE: 1,10,3,10,2, m 3, k 1 ->3.

At day2,only positions0 and4 bloom;day3 adds position2,allowing three single-flower bouquets.

Greedily taking the earliest k available consecutive flowers leaves the largest
remaining suffix; later days only add flowers.

O(n log(M+1)) time, O(1) space.

Check m>n/k before multiplying m*k.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> bouquet(const std::vector<int>& days, int m, int k) {
    assert(m >= 0 && k > 0);
    if (m == 0) {
        return 0;
    }
    if (m > static_cast<int>(days.size()) / k) {
        return std::nullopt;
    }
    int low = 0;
    int high = *std::max_element(days.begin(), days.end());
    while (low < high) {
        int mid = low + (high - low) / 2;
        int run = 0;
        int made = 0;
        for (int d : days) {
            assert(d >= 0);
            if (d <= mid) {
                ++run;
                if (run == k) {
                    ++made;
                    run = 0;
                }
            } else {
                run = 0;
            }
        }
        if (made >= m) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    assert(bouquet({1, 10, 3, 10, 2}, 3, 1) == 3);
    assert(!bouquet({1, 2}, 2, 2));
    assert(bouquet({}, 0, 2) == 0);
    assert(bouquet({0, 0}, 1, 2) == 0);
    std::cout << "checks passed\n";
    return 0;
}
