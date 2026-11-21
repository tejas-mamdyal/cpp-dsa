/*
 Nonnegative package weights; positive days; empty shipment 0.

IDEA AND STATE: A day takes the longest remaining prefix that fits; binary search its capacity.

TRACE: 1,2,3,4,5 with 3 days ->6.

Capacity5 packs1,2 then3 then4 then5,four days;capacity6 packs1,2,3 then4 then5,three days.

Finishing each day as far as possible leaves no more work than any
alternative; more capacity preserves feasibility.

O(n log(S+1)) time, O(1) auxiliary.

Reordering packages changes the problem.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

bool canSplitWork(const std::vector<int>& tasks, int groups, long long capacity) {
    if (groups < 1 || capacity < 0) {
        return false;
    }
    int used = 1;
    long long load = 0;
    for (int task : tasks) {
        assert(task >= 0);
        if (task > capacity) {
            return false;
        }
        if (load + task > capacity) {
            ++used;
            load = 0;
        }
        load += task;
    }
    return used <= groups;
}

std::optional<long long> split(const std::vector<int>& a, int k) {
    if (k < 1) {
        return std::nullopt;
    }
    long long low = 0;
    long long high = 0;
    for (int x : a) {
        assert(x >= 0);
        low = std::max(low, 1LL * x);
        high += x;
    }
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canSplitWork(a, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

std::optional<long long> shipping(const std::vector<int>& weights, int days) {
    return split(weights, days);
}

int main() {
    assert(shipping({1, 2, 3, 4, 5}, 3) == 6);
    assert(shipping({5}, 1) == 5);
    assert(shipping({}, 2) == 0);
    assert(!shipping({1}, 0));
    std::cout << "checks passed\n";
    return 0;
}
