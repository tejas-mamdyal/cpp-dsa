/*
 n<=8; unique value permutations, empty gives one empty ordering. Unless narrowed, at
most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic
owned structures; exponential searches use the smaller bounds stated here. No input; keep
assertions enabled. Success prints checks passed.

Sort and track used positions. The baseline generates positional
permutations then deduplicates.

For 1,1,2, the second 1 cannot start while the first 1 is unused, but can follow the
first 1 in the same route.

Canonical increasing use of equal positions gives one route per distinct value
ordering.

O((n+1)*n!+n log n) upper-bound time; O(n) auxiliary plus output.

The skip checks !used[i-1]; using used[i-1] instead changes which equivalent route
survives.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

void visit(const std::vector<int>& a,
           std::vector<bool>& used,
           std::vector<int>& path,
           std::vector<std::vector<int>>& out) {
    if (path.size() == a.size()) {
        out.push_back(path);
        return;
    }
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (used[i]) {
            continue;
        }
        if (i > 0 && a[i] == a[i - 1] && !used[i - 1]) {
            continue;
        }
        used[i] = true;       // Reserve this position for the active route.
        path.push_back(a[i]); // Choose this route element before exploring its completions.
        visit(a, used, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
        used[i] = false; // Restore availability for the next route.
    }
}

std::vector<std::vector<int>> uniquePermutations(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    std::vector<bool> used(a.size(), false);
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    visit(a, used, path, out);
    return out;
}

int main() {
    assert((uniquePermutations({1, 1, 2})
            == std::vector<std::vector<int>>{{1, 1, 2}, {1, 2, 1}, {2, 1, 1}}));
    assert(uniquePermutations({}).size() == 1);
    assert(uniquePermutations({2, 2}).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
