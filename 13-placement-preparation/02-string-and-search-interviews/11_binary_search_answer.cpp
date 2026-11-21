/*
 Positive weights, days>=1; empty shipment needs capacity 0. Unless a different bound
is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

Feasibility greedily fills consecutive days; larger capacities never need
more days.

Capacity 3 sends 1,2 together then 3 then 1,1, within 4 days.

For a fixed capacity, maximally filling each day cannot increase the number of
days; monotonicity justifies first-true search.

O(n log(sum weights+1)) time, O(1) work.

Order is fixed; sorting packages would solve a different problem.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>

bool possible(const std::vector<int>& weights, int days, int capacity) {
    int used = 1;
    int load = 0;
    for (int x : weights) {
        if (x > capacity) {
            return false;
        }
        if (load + x > capacity) {
            ++used;
            load = 0;
        }
        load += x;
    }
    return used <= days;
}

int capacity(const std::vector<int>& weights, int days) {
    if (weights.empty()) {
        return 0;
    }
    int low = *std::max_element(weights.begin(), weights.end());
    int high = std::accumulate(weights.begin(), weights.end(), 0);
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (possible(weights, days, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    assert(capacity({1, 2, 3, 1, 1}, 4) == 3);
    assert(capacity({3, 2, 2, 4, 1, 4}, 3) == 6);
    assert(capacity({}, 1) == 0);
    std::cout << "checks passed\n";
    return 0;
}
