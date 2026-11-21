/*
 Choose k distinct numbers from 1..n, n in [0,12]. Invalid k returns no answers; k=0
returns the one empty combination. No input is required. Keep assertions enabled; a successful
run prints checks passed. Tiny bounds are intentional because output grows exponentially or
factorially.

The baseline enumerates all subsets and filters sizes. need is the
unfilled count; start is the smallest still-eligible value. Stop if available values cannot
fill need.

n=4,k=2: prefix1 explores2,3,4;prefix2 explores3,4;prefix3 explores4. No prefix4
branch is needed because no second value remains.

Strictly increasing choices give each combination one route. The loop upper bound
removes only prefixes lacking enough remaining distinct values.

Conservative O((n+1)*2^n) time including output, O(n) auxiliary stack/path; exact output
storage O((k+1)*C(n,k)).

Without the increasing start, permutations of the same chosen set are repeated.
Pruning needs a proof, not a convenient sample.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

void choose(
    int n, int start, int need, std::vector<int>& path, std::vector<std::vector<int>>& out) {
    if (need == 0) {
        out.push_back(path);
        return;
    }
    if (n - start + 1 < need) {
        return;
    } // No completion can supply enough unused values.
    for (int value = start; value <= n - need + 1; ++value) {
        path.push_back(value);
        choose(n, value + 1, need - 1, path, out); // Later choices must be larger.
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinations(int n, int k) {
    assert(n >= 0 && n <= 12);
    if (k < 0 || k > n) {
        return {};
    }
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    choose(n, 1, k, path, out);
    return out;
}

int main() {
    assert((combinations(4, 2)
            == std::vector<std::vector<int>>{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}));
    assert((combinations(0, 0) == std::vector<std::vector<int>>{{}}));
    assert(combinations(3, 4).empty());
    assert(combinations(3, -1).empty());
    assert(combinations(4, 4).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
