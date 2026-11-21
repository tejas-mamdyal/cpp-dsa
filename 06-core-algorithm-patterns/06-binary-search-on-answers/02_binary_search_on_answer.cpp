/*
 Nonnegative tasks; positive k; empty work costs 0; return minimum largest contiguous
group sum.

IDEA AND STATE: Capacity feasibility packs each group as far as possible; search from max task
to total.

TRACE: 7,2,5,10,8 with k 2 ->18.

Capacity17 needs three groups;capacity18 packs7,2,5 then10,8 in two,so the first feasible
boundary is18.

Greedy ends each group no earlier than any feasible packing; larger capacities
cannot require more groups.

O(n log(S+1)) time, O(1) auxiliary, where S is total.

The predicate must reject an individual task above capacity even when outer bounds
usually prevent that call.
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

int main() {
    assert(split({7, 2, 5, 10, 8}, 2) == 18);
    assert(split({}, 1) == 0);
    assert(split({0, 0}, 5) == 0);
    assert(!split({1}, 0));
    assert(!canSplitWork({9}, 2, 8));
    std::cout << "checks passed\n";
    return 0;
}
