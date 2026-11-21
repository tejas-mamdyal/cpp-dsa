/*
 n<=12; distinct value-subsets from possibly repeated integers. Unless narrowed, at
most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic
owned structures; exponential searches use the smaller bounds stated here. No input; keep
assertions enabled. Success prints checks passed.

Sort a copy; start is the first eligible position. Save every current
prefix, then choose increasing later positions. Mask enumeration plus deduplication is a
simpler reference.

For 1,2,2, the root second 2 is skipped; prefix 1 may still choose both 2
values, so[1,2,2] remains legal.

At one depth equal first choices describe identical value completions; skipping
them removes duplicate routes without removing a multiplicity available deeper.

O(n*2^n+n log n) time including copies; O(n) auxiliary recursion/copy, plus output.

Skip only when i>start, not whenever neighboring values match.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

void visit(const std::vector<int>& a,
           std::size_t start,
           std::vector<int>& path,
           std::vector<std::vector<int>>& out) {
    out.push_back(path);
    for (std::size_t i = start; i < a.size(); ++i) {
        if (i > start && a[i] == a[i - 1]) {
            continue;
        }
        path.push_back(a[i]); // Choose this route element before exploring its completions.
        visit(a, i + 1, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
}

std::vector<std::vector<int>> uniqueSubsets(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    visit(a, 0, path, out);
    return out;
}

int main() {
    assert((uniqueSubsets({1, 2, 2})
            == std::vector<std::vector<int>>{{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}}));
    assert(uniqueSubsets({}).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
