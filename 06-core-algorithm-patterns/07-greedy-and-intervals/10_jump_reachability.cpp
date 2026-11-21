/*
 Nonnegative maximum jumps; empty route is considered already complete.

IDEA AND STATE: Scan while index<=farthest; extend the farthest reachable position.

TRACE: 2,3,1,1,4 ->true;3,2,1,0,4 ->false.

From index0,reach extends to2;index1 then extends to4,so every required index is reachable.

From a reachable index, every landing up to its maximum jump is reachable; their
union remains a prefix.

O(n) time, O(1) space.

The farthest index is reachability information, not necessarily a chosen path.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

bool reachable(const std::vector<int>& a) {
    long long far = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        assert(a[i] >= 0);
        if (i > far) {
            return false;
        }
        far = std::max(far, 1LL * i + a[i]);
    }
    return true;
}

bool slowReachable(const std::vector<int>& a) {
    if (a.empty()) {
        return true;
    }
    std::vector<bool> seen(a.size(), false);
    seen[0] = true;
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (seen[i]) {
            for (std::size_t j = i + 1; j < a.size() && j <= i + static_cast<std::size_t>(a[i]);
                 ++j) {
                seen[j] = true;
            }
        }
    }
    return seen.back();
}

int main() {
    assert(reachable({2, 3, 1, 1, 4}));
    assert(!reachable({3, 2, 1, 0, 4}));
    for (const auto& a :
         std::vector<std::vector<int>>{{}, {0}, {1, 0}, {2, 0, 1}, {0, 2}, {1, 1, 0}}) {
        assert(reachable(a) == slowReachable(a));
    }
    std::cout << "checks passed\n";
    return 0;
}
