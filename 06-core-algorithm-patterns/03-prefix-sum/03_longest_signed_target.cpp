/*
 Signed values; return longest nonempty target-sum length, or 0.

IDEA AND STATE: Store the first position of each prefix, not the latest.

TRACE: 1,-1,5,-2,3 target 3 ->4.

Prefix3 at endpoint4 matches initial prefix0,so indices0..4 give length4;later matches do not
improve it.

For a fixed end, the earliest matching preceding prefix gives the longest range.

Expected O(n) time, O(n) space.

Overwriting an earlier prefix position can shorten the answer.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>

int longestTarget(const std::vector<int>& a, long long target) {
    std::unordered_map<long long, int> first;
    first.emplace(0, -1);
    long long sum = 0;
    int best = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        sum += a[i];
        auto found = first.find(sum - target);
        if (found != first.end()) {
            best = std::max(best, i - found->second);
        }
        first.emplace(sum, i);
    }
    return best;
}

int main() {
    assert(longestTarget({1, -1, 5, -2, 3}, 3) == 4);
    assert(longestTarget({0, 0, 0}, 0) == 3);
    assert(longestTarget({}, 0) == 0);
    assert(longestTarget({-1, -1, 1}, 0) == 2);
    std::cout << "checks passed\n";
    return 0;
}
