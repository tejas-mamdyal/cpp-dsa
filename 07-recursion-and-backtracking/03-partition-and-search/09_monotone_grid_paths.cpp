/*
 Binary grid<=8x 8; only down/right moves through 1; count top-left to bottom-right
paths. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Coordinates strictly increase their sum, so a route cannot cycle. The brute
recursive baseline repeats suffix subproblems; DP is deferred.

An open 2 by 3 grid has DRR, RDR and RRD: one down and two rights, three paths.

Each legal route starts down or right; these disjoint cases sum to the total.

O(2^(R+C)) upper-bound time, O(R+C) frames.

Do not add memoization before its Phase 7 explanation; this is intentionally a
small-input baseline.
*/
#include <iostream>
#include <cassert>
#include <vector>

long long paths(const std::vector<std::vector<int>>& a, int r, int c) {
    if (a.empty() || r >= static_cast<int>(a.size()) || c >= static_cast<int>(a[0].size())
        || a[r][c] == 0) {
        return 0;
    }
    if (r == static_cast<int>(a.size()) - 1 && c == static_cast<int>(a[0].size()) - 1) {
        return 1;
    }
    return paths(a, r + 1, c) + paths(a, r, c + 1);
}

int main() {
    assert(paths({{1, 1, 1}, {1, 1, 1}}, 0, 0) == 3);
    assert(paths({{0}}, 0, 0) == 0);
    assert(paths({}, 0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
