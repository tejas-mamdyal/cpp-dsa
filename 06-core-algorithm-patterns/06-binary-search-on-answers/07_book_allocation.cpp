/*
 Nonnegative ordered pages;1<=students<=n; otherwise absent.

IDEA AND STATE: Use at-most feasibility then split existing groups until exactly k are
present.

TRACE: 12,34,67,90 with 2 ->113.

Capacity112 cannot put12,34,67 together;113 allows that group and90 as the second group.

Nonnegative pages mean subdividing a group cannot increase its maximum sum; there
are n available nonempty pieces.

O(n log(S+1)) time, O(1) auxiliary.

Unlike at-most groups, k>n is impossible.
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

std::optional<long long> books(const std::vector<int>& pages, int students) {
    if (students < 1 || students > static_cast<int>(pages.size())) {
        return std::nullopt;
    }
    return split(pages, students);
}

int main() {
    assert(books({12, 34, 67, 90}, 2) == 113);
    assert(!books({1}, 2));
    assert(!books({}, 1));
    assert(books({0, 0}, 2) == 0);
    std::cout << "checks passed\n";
    return 0;
}
