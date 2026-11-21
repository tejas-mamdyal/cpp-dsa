/*
 n<=12 positive candidates; target 0..20; duplicates allowed but output unique. Unless
narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume
valid acyclic owned structures; exponential searches use the smaller bounds stated here. No
input; keep assertions enabled. Success prints checks passed.

Same remaining-target model, but recurse from i+1. Skip equal candidates
only at the same choice depth.

10,1,2,7,6,1,5 at 8 gives 1,1,6;1,2,5;1,7;2,6.

Every selected position is consumed once, and equal siblings have the same value
completions.

O((n+1)*2^n+n log n) time; O(n) auxiliary plus output.

Moving from i rather than i+1 silently allows reuse.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

void visit(const std::vector<int>& a,
           std::size_t start,
           int remaining,
           bool reuse,
           std::vector<int>& path,
           std::vector<std::vector<int>>& out) {
    if (remaining == 0) {
        out.push_back(path);
        return;
    }
    for (std::size_t i = start; i < a.size(); ++i) {
        if (i > start && a[i] == a[i - 1]) {
            continue;
        }
        if (a[i] > remaining) {
            break;
        }
        path.push_back(a[i]); // Choose this route element before exploring its completions.
        visit(a, reuse ? i : i + 1, remaining - a[i], reuse, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
}

std::vector<std::vector<int>> sums(std::vector<int> a, int target, bool reuse) {
    assert(target >= 0 && target <= 20);
    for (int x : a) {
        assert(x > 0);
    }
    std::sort(a.begin(), a.end());
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    visit(a, 0, target, reuse, path, out);
    return out;
}

int main() {
    assert((sums({10, 1, 2, 7, 6, 1, 5}, 8, false)
            == std::vector<std::vector<int>>{{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}}));
    assert(sums({2}, 4, false).empty());
    assert(sums({1, 1}, 2, false).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
