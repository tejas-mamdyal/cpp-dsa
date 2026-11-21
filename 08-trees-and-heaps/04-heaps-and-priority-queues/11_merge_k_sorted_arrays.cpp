/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Heap tuples(value, row, index) identify the next candidate from each
nonempty row.

[1,4],[1,3],[],[2,6] pop 1,1,2,3,4,6.

Every unseen value is at least its row frontier; the minimum frontier is therefore
globally next.

O(N log(k+1)+k) time, O(k) heap plus output.

Enqueue only the successor from the row that just supplied an item.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>
#include <cstddef>

std::vector<int> merge(const std::vector<std::vector<int>>& rows) {
    using Item = std::tuple<int, std::size_t, std::size_t>;
    std::priority_queue<Item, std::vector<Item>, std::greater<Item>> q;
    for (std::size_t r = 0; r < rows.size(); ++r) {
        if (!rows[r].empty()) {
            q.emplace(rows[r][0], r, 0);
        }
    }
    std::vector<int> out;
    while (!q.empty()) {
        auto [value, r, i] = q.top();
        q.pop();
        out.push_back(value);
        if (i + 1 < rows[r].size()) {
            q.emplace(rows[r][i + 1], r, i + 1);
        }
    }
    return out;
}

int main() {
    assert((merge({{1, 4}, {1, 3}, {}, {2, 6}}) == std::vector<int>{1, 1, 2, 3, 4, 6}));
    assert(merge({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
