/*
 Rectangular nonnegative grid<=4x 4; zero blocked; positive values<=100; maximize a
nonrevisiting four-direction path sum. Unless narrowed, at most 100 nodes/elements with values
in [-1000,1000]. Recursive examples assume valid acyclic owned structures; exponential
searches use the smaller bounds stated here. No input; keep assertions enabled. Success prints
checks passed.

Choose a starting cell; temporarily set it to 0 to mark the route, then
restore its saved value.

0,6,0/5,8,7/0,9,0 has optimum 9+8+7=24.

Every simple route has a start and a legal first step; maximizing recursively over
neighbors covers all routes.

O(V*4^V) upper-bound time, O(V) call stack; grid restored.

Restoration must occur before returning the best score.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int collect(std::vector<std::vector<int>>& a, int r, int c) {
    if (r < 0 || c < 0 || r >= static_cast<int>(a.size()) || c >= static_cast<int>(a[0].size())
        || a[r][c] == 0) {
        return 0;
    }
    int value = a[r][c];
    a[r][c] = 0;
    int next = std::max(
        {collect(a, r + 1, c), collect(a, r - 1, c), collect(a, r, c + 1), collect(a, r, c - 1)});
    a[r][c] = value;
    return value + next;
}

int gold(std::vector<std::vector<int>>& a) {
    if (a.empty()) {
        return 0;
    }
    int best = 0;
    for (int r = 0; r < static_cast<int>(a.size()); ++r) {
        for (int c = 0; c < static_cast<int>(a[0].size()); ++c) {
            best = std::max(best, collect(a, r, c));
        }
    }
    return best;
}

int main() {
    std::vector<std::vector<int>> a{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    auto original = a;
    assert(gold(a) == 24);
    assert(a == original);
    a.clear();
    assert(gold(a) == 0);
    std::cout << "checks passed\n";
    return 0;
}
