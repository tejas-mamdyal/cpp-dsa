/*
 n 0..12; k 0..n; invalid k has no answers. Unless narrowed, at most 100 nodes/elements
with values in [-1000,1000]. Recursive examples assume valid acyclic owned structures;
exponential searches use the smaller bounds stated here. No input; keep assertions enabled.
Success prints checks passed.

Maintain combinations of each size; process each new value with sizes
descending so it is not reused.

For values 1 then 2, k 2, the descending update creates[1,2] from the previous size-one
list.

After processing value v, each combination using v extends exactly one previous
shorter combination; descending sizes prevent same-step reuse.

O(n*(k+1)*2^n) conservative time; O(n*2^n) saved partial/output storage.

Ascending size updates would reuse the current value.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

std::vector<std::vector<int>> combinations(int n, int k) {
    if (k < 0 || k > n) {
        return {};
    }
    std::vector<std::vector<std::vector<int>>> levels(static_cast<std::size_t>(k + 1));
    levels[0].push_back({});
    for (int value = 1; value <= n; ++value) {
        for (int size = std::min(k, value); size >= 1; --size) {
            for (auto path : levels[size - 1]) {
                path.push_back(
                    value); // Choose this route element before exploring its completions.
                levels[size].push_back(path);
            }
        }
    }
    return levels[k];
}

int main() {
    assert(combinations(4, 2).size() == 6);
    assert(combinations(0, 0).size() == 1);
    assert(combinations(2, 3).empty());
    assert((combinations(2, 2) == std::vector<std::vector<int>>{{1, 2}}));
    std::cout << "checks passed\n";
    return 0;
}
