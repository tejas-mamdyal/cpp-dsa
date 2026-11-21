/*
 At most 1000 bounded integer points; k>=0; return selected points sorted
by(distance, x, y). Unless narrowed, at most 100 nodes/elements with values in [-1000,1000].
Recursive examples assume valid acyclic owned structures; exponential searches use the smaller
bounds stated here. No input; keep assertions enabled. Success prints checks passed.

Max-heap tuples(distance, x, y) retain the smallest k ranks; compute squared
distance in long long.

(1,3),(-2,2),(2,-2) at k 1 chooses(-2,2) by the x tie.

Removing the largest retained rank after each insertion leaves exactly the k
smallest ranks seen.

O(n log(k+1)+k log(k+1)) time, O(k) space, with k capped at n.

Avoid floating square roots and document tie policy.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
#include <cstddef>

std::vector<std::pair<int, int>> closest(const std::vector<std::pair<int, int>>& points, int k) {
    assert(k >= 0);
    using Rank = std::tuple<long long, int, int>;
    std::priority_queue<Rank> q;
    for (auto [x, y] : points) {
        q.emplace(1LL * x * x + 1LL * y * y, x, y);
        if (q.size() > static_cast<std::size_t>(k)) {
            q.pop();
        }
    }
    std::vector<Rank> ranked;
    while (!q.empty()) {
        ranked.push_back(q.top());
        q.pop();
    }
    std::reverse(ranked.begin(), ranked.end());
    std::vector<std::pair<int, int>> out;
    for (auto [distance, x, y] : ranked) {
        (void)distance;
        out.emplace_back(x, y);
    }
    return out;
}

int main() {
    assert((closest({{1, 3}, {-2, 2}, {2, -2}}, 1) == std::vector<std::pair<int, int>>{{-2, 2}}));
    assert(closest({{1, 2}}, 0).empty());
    std::cout << "checks passed\n";
    return 0;
}
