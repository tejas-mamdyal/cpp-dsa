/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Count with map, then max-heap pairs(count,-value) so smaller value wins
equal frequency.

1,1,2,2,3 with k 2 returns 1,2.

Each heap pop removes the greatest remaining frequency with the specified value
tie break.

O(n log(n+1)+d log(d+1)) time, O(d) map/heap/output; d distinct.

Negating values is safe only under the bounded-value contract.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <queue>
#include <map>

std::vector<int> topFrequent(const std::vector<int>& a, int k) {
    assert(k >= 0);
    std::map<int, int> count;
    for (int x : a) {
        ++count[x];
    }
    std::priority_queue<std::pair<int, int>> q;
    for (auto item : count) {
        q.emplace(item.second, -item.first);
    }
    std::vector<int> out;
    while (k > 0 && !q.empty()) {
        out.push_back(-q.top().second);
        q.pop();
        --k;
    }
    return out;
}

int main() {
    assert((topFrequent({1, 1, 2, 2, 3}, 2) == std::vector<int>{1, 2}));
    assert(topFrequent({}, 3).empty());
    assert(topFrequent({1}, 0).empty());
    std::cout << "checks passed\n";
    return 0;
}
