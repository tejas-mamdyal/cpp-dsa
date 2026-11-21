/*
 n<=12; return distinct nondecreasing subsequences of length>=2. Unless narrowed, at
most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic
owned structures; exponential searches use the smaller bounds stated here. No input; keep
assertions enabled. Success prints checks passed.

At each depth keep a set of values already tried; accept only choices
>=last value. Sorting the input would solve a different problem.

4,6,7,7 includes 4,7,7 but emits 4,7 only once.

Equal next values at the same depth have identical later value
completions; keeping the earliest leaves at least as many future positions.

O((n+1)*2^n*log(n+1)) conservative time; O(n^2) active per-level sets/path plus output.

The set is local to a depth, not global across the whole search.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <cstddef>

void visit(const std::vector<int>& a,
           std::size_t start,
           std::vector<int>& path,
           std::vector<std::vector<int>>& out) {
    if (path.size() >= 2) {
        out.push_back(path);
    }
    std::set<int> tried;
    for (std::size_t i = start; i < a.size(); ++i) {
        if (!path.empty() && a[i] < path.back()) {
            continue;
        }
        if (!tried.insert(a[i]).second) {
            continue;
        }
        path.push_back(a[i]); // Choose this route element before exploring its completions.
        visit(a, i + 1, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
}

int main() {
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    visit({4, 6, 7, 7}, 0, path, out);
    assert(out.size() == 8);
    assert(std::set<std::vector<int>>(out.begin(), out.end()).size() == out.size());
    std::cout << "checks passed\n";
    return 0;
}
